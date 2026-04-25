def compare_asc(x, y):
    return x > y


def compare_desc(x, y):
    return x < y


def compare_abs(x, y):
    if abs(x) == abs(y):
        if x < y:
            return True

        return False

    return abs(x) > abs(y)
