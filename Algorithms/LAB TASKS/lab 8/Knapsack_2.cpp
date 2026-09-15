#include "bits/stdc++.h"
using namespace std;

const long long INF = 1e18;

int main()
{
    int n;
    long long w;
    cin >> n >> w;

    vector<vector<long long>> items(n + 1, vector<long long>(2));
    int max_possible_value = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> items[i][0] >> items[i][1];
        max_possible_value += items[i][1];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(max_possible_value + 1, INF));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_possible_value; j++)
        {
            if (items[i][1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - items[i][1]] + items[i][0]);
        }
    }

    int best_value = 0;
    for (int j = 0; j <= max_possible_value; j++)
    {
        if (dp[n][j] <= w)
            best_value = j;
    }

    cout << best_value << endl;
}