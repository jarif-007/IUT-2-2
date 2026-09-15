#include "bits/stdc++.h"
using namespace std;

const long long MIN_INF = -2e18;

long long maxCrossingSum(const vector<long long> &arr, int low, int mid, int high)
{
    long long sum = 0;
    long long left_sum = MIN_INF;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    long long right_sum = MIN_INF;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

long long maxSubarraySum(const vector<long long> &arr, int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    long long left_max = maxSubarraySum(arr, low, mid);
    long long right_max = maxSubarraySum(arr, mid + 1, high);
    long long cross_max = maxCrossingSum(arr, low, mid, high);

    return max({left_max, right_max, cross_max});
}

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long ans = maxSubarraySum(arr, 0, n - 1);
    cout << ans << endl;
}