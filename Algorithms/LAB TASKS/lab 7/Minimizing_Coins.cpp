#include "bits/stdc++.h"
using namespace std;

const int INF = 1e8;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (auto &coin : coins)
        {
            if (i - coin >= 0)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    
    if (dp[x] == INF)
        cout << "-1\n";
    else
        cout << dp[x] << endl;
}