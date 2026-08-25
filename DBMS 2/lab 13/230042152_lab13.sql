-- ============================================================================
--  IUT LAUNDRY MANAGEMENT SYSTEM
--  PostgreSQL implementation
-- ============================================================================
--
--  DESIGN NOTES / ASSUMPTIONS (read this before grading/using):
--
--  1. Requirement: entry_number must be auto-generated, never typed by the
--     manager. This is solved with GENERATED ALWAYS AS IDENTITY, which is
--     PostgreSQL's modern replacement for SERIAL. The manager's INSERT/CALL
--     never mentions entry_number at all.
--
--  2. Requirement: a 7-day turnaround, with "combine if within 7 days" /
--     "warn and reject if after 7 days and not yet collected". To evaluate
--     "already collected/delivered" the table needs a status flag, since the
--     spec doesn't give one otherwise. I added a `status` column
--     ('Pending' / 'Collected') to cloth_owner_info for this purpose. This
--     is the only extra attribute added beyond what the spec lists.
--
--  3. "The date should be adjusted accordingly" (on combine): interpreted as
--     resetting submission_date to the date of the *new* visit, since that
--     is when the laundry actually has all the clothes in hand and the
--     7-day clock should restart from there.
--
--  4. "Delete the previous order" on combine: the old row is deleted and a
--     new row is inserted with the combined clothes count. Because
--     entry_number is auto-generated, the combined order gets a fresh
--     entry_number -- this matches "the entry number is large/sequential
--     and the manager shouldn't touch it" (i.e. it's not meant to be a
--     stable ID the manager tracks by memory anyway).
--
--  5. Only one PENDING order per student is expected at a time (a student
--     can't submit new clothes while an old pending order is unresolved
--     inside the 7-day window without it being combined, and outside the
--     window they're blocked until they collect). This is enforced by
--     application logic (the procedure), not a table constraint, since
--     PostgreSQL can't easily express "unique pending row per student" as
--     a plain constraint without a partial unique index -- which is added
--     below anyway as a safety net.
-- ============================================================================


-- ----------------------------------------------------------------------------
-- 0. Clean slate (safe to re-run while developing/testing)
-- ----------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS submit_clothes(VARCHAR, VARCHAR, INT);
DROP PROCEDURE IF EXISTS collect_clothes(INT);
DROP VIEW IF EXISTS overdue_uncollected_orders;
DROP TABLE IF EXISTS cloth_owner_info;


-- ----------------------------------------------------------------------------
-- 1. Table: cloth_owner_info
-- ----------------------------------------------------------------------------
CREATE TABLE cloth_owner_info (
    entry_number     INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    student_name     VARCHAR(100)  NOT NULL,
    student_id       VARCHAR(20)   NOT NULL,
    num_clothes      INT           NOT NULL CHECK (num_clothes > 0),
    submission_date  DATE          NOT NULL DEFAULT CURRENT_DATE,
    status           VARCHAR(20)   NOT NULL DEFAULT 'Pending'
                                    CHECK (status IN ('Pending', 'Collected'))
);

-- Safety net: a student can only have ONE pending (uncollected) order
-- at any given time. This mirrors the business rule the assignment
-- describes and prevents duplicate pending rows from ever existing.
CREATE UNIQUE INDEX one_pending_order_per_student
    ON cloth_owner_info (student_id)
    WHERE status = 'Pending';


-- ----------------------------------------------------------------------------
-- 2. Procedure: submit_clothes
--    Called by the manager every time a student drops off clothes.
--    Handles the 7-day combine / reject-with-warning logic automatically.
--    The manager only ever supplies name, student id, and clothes count.
-- ----------------------------------------------------------------------------
CREATE OR REPLACE PROCEDURE submit_clothes(
    p_student_name  VARCHAR,
    p_student_id    VARCHAR,
    p_num_clothes   INT
)
LANGUAGE plpgsql
AS $$
DECLARE
    v_entry_number    INT;
    v_old_num_clothes INT;
    v_submission_date DATE;
    v_days_since      INT;
BEGIN
    -- Look for this student's current pending (not-yet-collected) order
    SELECT entry_number, num_clothes, submission_date
    INTO   v_entry_number, v_old_num_clothes, v_submission_date
    FROM   cloth_owner_info
    WHERE  student_id = p_student_id
      AND  status = 'Pending';

    IF NOT FOUND THEN
        -- No unresolved order on file -> plain new submission
        INSERT INTO cloth_owner_info (student_name, student_id, num_clothes, submission_date, status)
        VALUES (p_student_name, p_student_id, p_num_clothes, CURRENT_DATE, 'Pending');

        RAISE NOTICE 'New order recorded for % (ID: %) - % clothes, submitted %.',
            p_student_name, p_student_id, p_num_clothes, CURRENT_DATE;
        RETURN;
    END IF;

    v_days_since := CURRENT_DATE - v_submission_date;

    IF v_days_since >= 7 THEN
        -- 7+ days have passed and the earlier order is STILL pending,
        -- i.e. the student never collected their clean clothes.
        -- Reject the new drop-off.
        RAISE WARNING
            'REJECTED: % (ID: %) still has an uncollected order from % (Entry #%, % clothes). New clothes were NOT accepted.',
            p_student_name, p_student_id, v_submission_date, v_entry_number, v_old_num_clothes;
        RETURN;
    ELSE
        -- Within the 7-day window -> merge the new drop-off into the
        -- existing pending order instead of creating a second one.
        DELETE FROM cloth_owner_info WHERE entry_number = v_entry_number;

        INSERT INTO cloth_owner_info (student_name, student_id, num_clothes, submission_date, status)
        VALUES (p_student_name, p_student_id, v_old_num_clothes + p_num_clothes, CURRENT_DATE, 'Pending');

        RAISE NOTICE
            'COMBINED: % (ID: %) - previous Entry #% (% clothes) merged with new drop-off (% clothes). New total: % clothes, date reset to %.',
            p_student_name, p_student_id, v_entry_number, v_old_num_clothes,
            p_num_clothes, v_old_num_clothes + p_num_clothes, CURRENT_DATE;
    END IF;
END;
$$;


-- ----------------------------------------------------------------------------
-- 3. Procedure: collect_clothes
--    Called by the manager when a student picks up their cleaned clothes.
--    Not explicitly required by the spec, but necessary in practice --
--    without it, no order could ever reach 'Collected' status, and the
--    7-day check in submit_clothes would have nothing to test against.
-- ----------------------------------------------------------------------------
CREATE OR REPLACE PROCEDURE collect_clothes(p_entry_number INT)
LANGUAGE plpgsql
AS $$
BEGIN
    UPDATE cloth_owner_info
    SET    status = 'Collected'
    WHERE  entry_number = p_entry_number
      AND  status = 'Pending';

    IF NOT FOUND THEN
        RAISE WARNING 'No pending order found with Entry #%.', p_entry_number;
    ELSE
        RAISE NOTICE 'Entry #% marked as collected.', p_entry_number;
    END IF;
END;
$$;


-- ----------------------------------------------------------------------------
-- 4. Convenience view: orders that are overdue AND still uncollected
--    (useful for the manager to see who to chase up / who will be
--    rejected if they try to submit new clothes today)
-- ----------------------------------------------------------------------------
CREATE VIEW overdue_uncollected_orders AS
SELECT entry_number, student_name, student_id, num_clothes,
       submission_date, CURRENT_DATE - submission_date AS days_pending
FROM   cloth_owner_info
WHERE  status = 'Pending'
  AND  CURRENT_DATE - submission_date >= 7;


-- ============================================================================
--  5. DEMO / TEST SCRIPT
--     Walks through all three behaviours described in the assignment.
--     Dates are manipulated with direct UPDATEs afterward purely to
--     *simulate the passage of time* for testing -- in real use,
--     submission_date is always just CURRENT_DATE.
-- ============================================================================

-- Case A: fresh submission (no prior order on file)
CALL submit_clothes('Rafiq Islam', '190041101', 5);

-- Case B: same student comes back 3 days later (within 7 days) -> combine
UPDATE cloth_owner_info
SET submission_date = CURRENT_DATE - 3
WHERE student_id = '190041101';

CALL submit_clothes('Rafiq Islam', '190041101', 2);
-- Expect: combined into ONE row with 7 clothes, submission_date reset to today

-- Case C: a different student, order goes unresolved past 7 days -> warning + reject
CALL submit_clothes('Nusrat Jahan', '190041102', 4);

UPDATE cloth_owner_info
SET submission_date = CURRENT_DATE - 8
WHERE student_id = '190041102';

CALL submit_clothes('Nusrat Jahan', '190041102', 3);
-- Expect: WARNING, new clothes rejected, original 4-cloth order untouched

-- Case D: same overdue student FIRST collects, THEN submits again -> accepted as new order
-- (CALL does not accept a subquery directly as an argument in PostgreSQL,
--  so the entry_number is fetched into a variable first)
DO $$
DECLARE
    v_entry_number INT;
BEGIN
    SELECT entry_number INTO v_entry_number
    FROM cloth_owner_info
    WHERE student_id = '190041102' AND status = 'Pending';

    CALL collect_clothes(v_entry_number);
END;
$$;

CALL submit_clothes('Nusrat Jahan', '190041102', 3);
-- Expect: new row created, since the old one is now 'Collected'

-- Inspect final state
SELECT * FROM cloth_owner_info ORDER BY entry_number;

-- Check the overdue view (should be empty at this point in the demo)
SELECT * FROM overdue_uncollected_orders;