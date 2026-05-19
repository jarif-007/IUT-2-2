from comparator import *


def merge_sort(arr, compare=compare_asc):

    if len(arr) == 1:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[:mid], compare)
    right = merge_sort(arr[mid:], compare)

    return merge(left, right, compare)


def merge(left, right, compare):

    result = []
    i = j = 0

    while i < len(left) and j < len(right):

        if not compare(left[i], right[j]):
            result.append(left[i])
            i += 1

        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result


def main():
    arr = [1, -2, 5, 0, -3]

    a = merge_sort(arr)
    b = merge_sort(arr, compare_desc)
    c = merge_sort(arr, compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
