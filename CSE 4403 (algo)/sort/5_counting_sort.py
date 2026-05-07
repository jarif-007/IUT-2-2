from comparator import *


def counting_sort(arr, compare=compare_asc):
    """
        only works for ascending & desceding
    """

    min_val = min(arr)
    max_val = max(arr)

    # separate-chained hash_table
    count_table = [[] for _ in range(max_val - min_val + 1)]
    for num in arr:
        count_table[num - min_val].append(num)

    # flattening buckets into a flat-list
    i = 0
    for bucket in count_table:
        for num in bucket:
            arr[i] = num
            i += 1

    if compare == compare_desc:
        arr.reverse()


def main():
    a = [1, -2, 5, 0, -3]
    b = a.copy()

    counting_sort(a)
    counting_sort(b, compare_desc)

    print(a)
    print(b)


if __name__ == "__main__":
    main()
