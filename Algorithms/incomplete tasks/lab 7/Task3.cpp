#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= k; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    for (int i = k + 1; i <= n; i++)
    {
        
    }
}