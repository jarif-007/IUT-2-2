def digit_count(n):

    if n == 0:
        return 1

    digits = 0
    while n > 0:
        digits += 1
        n //= 10

    return digits


def count_sort(arr, digit_place):

    count_table = [[] for _ in range(10)]
    exp = pow(10, digit_place)

    # Put numbers into buckets
    for num in arr:
        index = (num // exp) % 10
        count_table[index].append(num)

    # Flatten buckets back into array
    i = 0
    for bucket in count_table:
        for num in bucket:
            arr[i] = num
            i += 1


def radix_sort(arr):

    max_val = max(arr)
    digits = digit_count(max_val)

    for i in range(digits):
        count_sort(arr, i)


def main():
    arr = [99, 11, 22, 77, 88, 66, 55, 44, 33, 13, 57]
    radix_sort(arr)

    print(arr)


if __name__ == "__main__":
    main()
