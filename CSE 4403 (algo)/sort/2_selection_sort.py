import comparator

def selection_sort(arr, compare=comparator.compare_asc):

    for i in range(len(arr) - 1):

        val = arr[i]
        index = i

        for j in range(index, len(arr)):

            if compare(val, arr[j]):
                val = arr[j]
                index = j

        arr[i], arr[index] = arr[index], arr[i]


def main():
    a = [1, -2, 5, 0, -3]
    b = a.copy()
    c = a.copy()

    selection_sort(a)
    selection_sort(b, comparator.compare_desc)
    selection_sort(c, comparator.compare_abs)

    print(a)
    print(b)
    print(c)


if __name__ == "__main__":
    main()
