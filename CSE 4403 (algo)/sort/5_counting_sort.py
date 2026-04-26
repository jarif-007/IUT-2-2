# someone kindly help how to make this sort work for asc, desc and abs 

def counting_sort(arr):
    """only works for ascending"""

    min_val = min(arr)
    max_val = max(arr)

    # Count frequency
    count = [0] * (max_val - min_val + 1)
    for num in arr:
        count[num - min_val] += 1

    # converting count to prefix_sum
    prefix = count
    for i in range(1, len(prefix)):
        prefix[i] += prefix[i - 1]

    # converting prefix to index
    index = prefix
    for i in range(len(index) - 1, 0, -1):
        index[i] = index[i - 1]

    index[0] = 0
    ans = [None] * len(arr)

    for num in arr:
        ans[index[num - min_val]] = num
        index[num - min_val] += 1

    print(ans)


def main():
    a = [1, -2, 5, 0, -3]
    a = counting_sort(a)
    # print(a)


if __name__ == "__main__":
    main()
