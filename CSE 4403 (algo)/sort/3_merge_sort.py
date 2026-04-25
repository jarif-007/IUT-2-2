import comparator


def merge_sort(arr, compare=comparator.compare_asc):

    if len(arr) == 1:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[:mid], compare)
    right = merge_sort(arr[mid:], compare)

    return merge(left, right, compare)


def merge(arr1, arr2, compare):

    result = []
    i = j = 0

    while i < len(arr1) and j < len(arr2):

        if not compare(arr1[i], arr2[j]):
            result.append(arr1[i])
            i += 1

        else:
            result.append(arr2[j])
            j += 1

    result.extend(arr1[i:])
    result.extend(arr2[j:])

    return result


def main():
    arr = [1, -2, 5, 0, -3]

    a = merge_sort(arr)
    b = merge_sort(arr, comparator.compare_desc)
    c = merge_sort(arr, comparator.compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
