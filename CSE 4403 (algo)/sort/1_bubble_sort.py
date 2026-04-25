import comparator


def bubble_sort(arr, compare=comparator.compare_asc):
    swap_count = -1
    while swap_count != 0:
        swap_count = 0

        for i in range(len(arr) - 1):
            if compare(arr[i], arr[i + 1]):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swap_count += 1


def main():
    a = [1, -2, 5, 0, -3]
    b = a.copy()
    c = a.copy()

    bubble_sort(a)
    bubble_sort(b, comparator.compare_desc)
    bubble_sort(c, comparator.compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
