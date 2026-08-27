#include "bits/stdc++.h"
using namespace std;

bool compare(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    return a.second * b.first > b.second * a.first;
}

int main()
{
    long long N, W;
    cin >> N >> W;

    vector<pair<long long, long long>> items(N);
    for (long long i = 0; i < N; i++)
    {
        long long w, v;
        cin >> w >> v;

        items[i] = {w, v};
    }

    sort(items.begin(), items.end(), compare);

    long long totalValue = 0;
    long long remaining = W;

    for (auto &[w, v] : items)
    {
        if (w > remaining)
        {
            totalValue += (1.0 * remaining / w) * v;
            break;
        }

        totalValue += v;
        remaining -= w;
    }

    cout << totalValue << endl;
}