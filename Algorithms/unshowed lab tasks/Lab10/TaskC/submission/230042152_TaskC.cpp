#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<pair<long long, long long>> fruits(n);
        for (int i = 0; i < n; i++)
            cin >> fruits[i].first;

        for (int i = 0; i < n; i++)
            cin >> fruits[i].second;

        sort(fruits.begin(), fruits.end());
        priority_queue<
            long long,
            vector<long long>,
            greater<long long>>
            pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(fruits[i].second);

            if (pq.size() > fruits[i].first)
                pq.pop();
        }

        long long totalProfit = 0;
        while (!pq.empty())
        {
            totalProfit += pq.top();
            pq.pop();
        }

        cout << totalProfit << endl;
    }
}