#include "bits/stdc++.h"
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    for (auto &num : arr)
        cout << num << " ";
}