# LECTURE 8: ENGINEERING ETHICS
**Core Principle:** Legal compliance = floor, not ceiling. Prioritize public safety.

**Case Studies:**
*   **Case: Citicorp Center (LeMessurier)**
    *   → Problem: Hidden weak bolts + 40% more wind force = collapse risk.
    *   → Lesson: Disclosing mistake & fixing (secret welding) enhanced reputation; didn't destroy it.
*   **Case: GE & GM (Headlights/Lamps)**
    *   → Problem: Proprietary safety tech vs public safety.
    *   → Lesson: Duty to share safety advances industry-wide, even if costing competitive edge.
*   **Case: NHTSA vs. IIHS**
    *   → Problem: NHTSA (binding/frontal) vs IIHS (nonprofit/offset). Car passes legal but fails offset.
    *   → Lesson: Don't ignore better safety data just because design meets legal minimum.

**3 Excuses (Impediments to Ethics):**
1.  "Not my problem" → False. Unsafe products raise prices/taxes/insurance for all.
2.  "If I don't, someone else will" → Being first to build harm isn't an achievement.
3.  "I can't foresee everything" → Build foresight into design; if mistake happens, step up & fix.

---

# LECTURE 9: AI BIAS & FAIRNESS
**Bias Definition:** Prejudice for/against thing/person/group vs another.

**Causes in Tech:** 1. Incomplete Data 2. Human Perceptions (tags).

**Bias Across Software Lifecycle:**
*   Requirements → Whose needs are defined?
*   Data Collection → Selection/time/observer biases.
*   Modeling → Bias-variance trade-off.
*   Testing → Subgroup evaluation (not just overall avg).
*   Deployment → Automated & complacency bias.

**Types of Bias:**
*   **Sociological:** Racism, Sexism, Ageism (excluding elderly ui), Religious Prejudice.
*   **Implicit:** Unconscious stereotypes. Often contradict conscious beliefs.
    *   *Affinity Bias* → Favoring people similar to us.
*   **Cognitive (Mental Shortcuts):** (Hook: "FAAO")
    *   **F**alse Consensus → Overestimate how normal our own views are.
    *   **A**nchoring → Over-reliance on 1st piece of info.
    *   **A**ttribution Error → Judge others by character, not circumstances.
    *   **O**ptimism Bias → Believe negative risks apply less to you than others.
*   **Systemic/Human-Machine Biases:**
    *   **Confirmation Bias:** 1. Hypothesize → 2. Seek favorable info (ignore rest) → 3. Publish.
    *   **Complacency Bias:** Trust machine > human.
    *   **Automated Bias:** Trust machine implicitly → Stop monitoring → "Omission errors" (the miss) go undetected.

**Data & Statistical Biases:**
*   **Data Collection Biases:**
    *   Selection → Not randomized/representative.
    *   Time Interval → Too narrow time frame.
    *   Observer → Humans collecting data judge via cognitive bias.
    *   Misclassification → Mislabeled data.
*   **Statistical Biases:**
    *   Outliers → Drastically different points.
    *   Underfitting → Removed too many variables; model fails to learn.
    *   Overestimating Rule → Initially include as many variables as possible.
    *   Uncorrelated Data → Must remove (e.g., ice cream sales & drowning).

**Modeling Bias (The Trade-off):**
*   **Bias** = Matches training set exactly. 
*   **Variance** = Flexibility with different data.
*   **Underfit** → High Bias + Low Variance (Too simple).
*   **Overfit** → Low Bias + High Variance (Memorized data, fails new data).
*   **Goal** → Low Bias + Low Variance (Minimizes "Generalization Error").

**Fairness Metrics & Ethics:**
*   **Demographic Parity** → Equal outcome rates across groups (regardless of qual).
*   **Equalized Odds** → Equal error rates (false +/-) across groups.
*   **The Impossibility Result** → Mathematically impossible to satisfy both if base rates differ. Choosing is an ethical decision, must explicitly document.

**Engineer’s 6 Responsibilities:**
1. Audit Data
2. Test Subgroups
3. Diversify Team
4. Document/Disclose limitations
5. Don't Automate Blindly (Human in loop)
6. Speak Up.

**Case Studies:**
*   **Case: Gender Shades (Facial Recog)**
    *   → Problem: Trained on white males. Failed on women/POC.
    *   → Causes: Selection Bias + Modeling Bias + Sociological Bias.
*   **Case: COMPAS (Recidivism Algorithm)**
    *   → Problem: False high-risk for Black defendants; false low-risk for White defendants.
    *   → Lesson: Equal overall accuracy != Equalized Odds. Kept as "trade secret" (unauditable).

---

# LECTURE 10: RECOMMENDER SYSTEMS & MODERATION
**Recommender Systems:** Maximize engagement → Spreads lies 6.5x faster than truth.
**Moderation Methods:** 
1. Take Down 
2. Demote (pushes to bottom) 
3. Flag (marks false + context).

**Case Studies:**
*   **Case: "Innocence of Muslims" (YouTube)**
    *   → Problem: False video → Violent protests/deaths. YT refused takedown.
    *   → Generalizability: Removing inciting violence = generalizable. Removing *all* lies = not generalizable (destroys utility).
    *   → Utilitarian: YT consequences matter, even if rioters caused immediate harm.
    *   → Free Speech: 1st Amendment restricts Govt, not YT.
    *   → Autonomy Principle: Bystanders hurt in riot didn't consent (Violation).
    *   → Compromise: Flag + reliable sources (satisfies utility & speech).
*   **Case: Teen Mental Health vs Social Media**
    *   → Problem: Spikes in depression linking to SM use.
    *   → Autonomy: Banning kids != violation (no right to access). Kids cannot give *informed consent*.
    *   → Lesson: Utilitarian benefits (fun/edu) cannot outweigh autonomy violation (harm) for kids.

---

# LECTURE 11: LLMs & GANS
**LLM Mechanics:** 
- Word associations. 
- Uses *Spatial Word Embedding* (words = points in high-dim space, reduced via singular value decomposition). 
- No actual understanding; 

**GANs (Generative Adversarial Networks):**
*   **Generator** (makes fakes) vs **Discriminator** (tries to catch fakes) → hyper-realistic output.
*   **ChatGPT Flaws:** Pre-trained (no live learning), Hallucinations (invents fake facts/images).

**Ethics of AI Writing:**
*   **Generalization Argument 1 (Implied Promise):** Author promises original thought. GPT breaks this.
*   **Generalization Argument 2 (Garbage Loop):** AI trains on human data. If humans stop writing → AI eats AI data → "Garbage in, garbage out".
*   **Exceptions:** Boilerplate/routine text. Assisted writing (if edited/fact-checked).
*   **Utilitarian Argument:** Writing builds literacy/reasoning. Using GPT deprives society of skilled thinkers.

**Misuse & Jailbreaking:**
*   **Jailbreaking:** Tricking AI to bypass safety rules.
*   **Techniques:** Role-play, multi-step reasoning, obfuscation/encoding, prompt injection.
*   **Lesson:** Security researchers do this responsibly to patch flaws. Engineers must design robust defenses.

---

# LECTURE 12: IP & GENERATIVE AI
**The AI IP Problem:**
*   **Scraping:** Downloading bulk public data without permission/pay.
*   **The Garbage Loop Test:** Scrape free → nobody pays creators → creation stops → nothing left to scrape. (Root issue = funding problem, e.g., NYT Lawsuit).
*   **IP Nature:** Ideas cannot be owned. Copying != Taking (Non-exclusive). Patent = trade (disclose for 20yr monopoly).

**TRIPS Agreement:** WTO treaty (1994). Sets global *minimum* baseline protections (Floor, not ceiling).

**The 4 Kinds of Intellectual Property:**
**1. Copyright**
*   → Protects: *Expression* of idea (code, text, art). NOT the idea/algorithm itself.
*   → Acquired: Automatically on creation.
*   → Lifespan: Life + 50 yrs (TRIPS min). US: Life + 70, or 95 (Corporate - e.g., Steamboat Willie).
*   → Fair Use: Allowed for criticism, news, teaching, research.
*   → Software: Yes (source code).

**2. Trademark**
*   → Protects: Brand identity (logo/name identifying source).
*   → Acquired: Commercial use or registration.
*   → Lifespan: Indefinite (if in commercial use).
*   → Rule: Class-specific (Apple records vs Apple computers).

**3. Patent**
*   → Protects: New method, device, material.
*   → Acquired: Apply + Exam + Public Disclosure.
*   → Lifespan: 20 years.
*   → Exclusions (Cannot Patent): Pure ideas (math), Nature (DNA), Biz methods, "Look and feel".
*   → Software: Yes, ONLY if it improves computer functionality (Not just "doing X on a computer").

**4. Trade Secret**
*   → Protects: Secret info giving commercial advantage (e.g., Coca-Cola formula).
*   → Acquired: Keeping it secret.
*   → Lifespan: Indefinite (until leaked/discovered).
*   → Rule: Legal to reverse engineer or figure out independently. Illegal to steal docs. NDAs used for employees.