#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

vector<long long> bellmanFord(long long n, long long src, vector<tuple<long long, long long, long long>> &edges)
{
    vector<long long> dist(n + 1, INF);
    dist[src] = 0;

    for (long long i = 0; i < n; i++)
    {
        for (auto &[u, v, wt] : edges)
        {
            if (dist[u] == INF)
                continue;

            if (dist[u] + wt < dist[v])
            {
                if (i == n - 1)
                    return vector<long long>(n + 1, -INF);

                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<tuple<long long, long long, long long>> edges;
    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        long long wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, -wt});
    }

    long long src = 1;
    vector<long long> dist = bellmanFord(n, src, edges);

    if (dist[n] == -INF)
        cout << "-1\n";
    else
        cout << -dist[n] << endl;
}