from comparator import *


def insertion_sort(arr, compare=compare_asc):

    # starting from 1 as 0 is already sorted
    for i in range(1, len(arr)):

        pos = i

        while pos > 0 and not compare(arr[pos], arr[pos - 1]):
            arr[pos], arr[pos - 1] = arr[pos - 1], arr[pos]
            pos -= 1


def main():
    a = [1, -2, 5, 0, -3]
    b = a.copy()
    c = a.copy()

    insertion_sort(a)
    insertion_sort(b, compare_desc)
    insertion_sort(c, compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
