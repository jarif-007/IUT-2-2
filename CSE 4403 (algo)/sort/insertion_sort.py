def insertion_sort(arr):

    # starting from 1 as 0 is already sorted
    for i in range(1, len(arr)):
    
        pos = i

        while pos > 0 and arr[pos] < arr[pos - 1]:
            arr[pos], arr[pos - 1] = arr[pos - 1], arr[pos]
            pos -= 1


def main():
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    insertion_sort(arr)

    print(arr)


if __name__ == "__main__":
    main()
