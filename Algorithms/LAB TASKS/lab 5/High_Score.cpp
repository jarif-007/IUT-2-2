#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<tuple<long long, long long, long long>> edges;
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, -wt});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (long long i = 0; i < n; i++)
    {
        for (auto &[u, v, wt] : edges)
        {
            if (dist[u] != INF && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for (long long i = 0; i < n; i++)
    {
        for (auto &[u, v, wt] : edges)
        {
            if (dist[u] != INF && dist[u] + wt < dist[v])
                dist[v] = -INF;
        }
    }

    dist[n] == -INF ? cout << -1 << endl : cout << -dist[n] << endl;
}