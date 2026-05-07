from comparator import *

def bubble_sort(arr, compare=compare_asc):
    swapped = True
    while swapped:
        swapped = False

        for i in range(len(arr) - 1):
            if compare(arr[i], arr[i + 1]):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True


def main():
    a = [1, -2, 5, 0, -3]
    b = a.copy()
    c = a.copy()

    bubble_sort(a)
    bubble_sort(b, compare_desc)
    bubble_sort(c, compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
