# someone kindly help how to make this sort work for asc, desc and abs


def counting_sort(arr):
    """only works for ascending"""

    min_val = min(arr)
    max_val = max(arr)

    # open-addressed hash_table
    count_table = [[] for _ in range(max_val - min_val + 1)]
    for num in arr:
        count_table[num - min_val].append(num)

    # flattening buckets into a flat-list
    i = 0
    for bucket in count_table:
        for num in bucket:
            arr[i] = num
            i += 1


def main():
    a = [1, -2, 5, 0, -3]
    counting_sort(a)
    print(a)


if __name__ == "__main__":
    main()
