#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<long long, long long>> jobs(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].first >> jobs[i].second;

    sort(jobs.begin(), jobs.end());
    priority_queue<
        long long,
        vector<long long>,
        greater<long long>>
        pq;

    for (int i = 0; i < n; i++)
    {
        long long start = jobs[i].first;
        long long finish = jobs[i].second;

        if (!pq.empty() && pq.top() <= start)
            pq.pop();

        pq.push(finish);
    }

    cout << pq.size() << endl;
}