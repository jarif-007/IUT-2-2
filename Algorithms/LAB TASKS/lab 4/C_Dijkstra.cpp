#include <bits/stdc++.h>
using namespace std;

void dijkstra(long long src,
              vector<vector<pair<long long, long long>>> &adj,
              vector<long long> &dist,
              vector<long long> &parent);

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n);

    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;

        u--;
        v--;

        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> parent(n, -1);

    dijkstra(0, adj, dist, parent);

    if (dist[n - 1] == LLONG_MAX)
    {
        cout << -1;
        return 0;
    }

    vector<long long> path;

    for (long long v = n - 1; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (long long v : path)
        cout << v + 1 << " ";

    return 0;
}

void dijkstra(long long src,
              vector<vector<pair<long long, long long>>> &adj,
              vector<long long> &dist,
              vector<long long> &parent)
{
    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>>
        pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (dist_u > dist[u])
            continue;

        for (auto &[wt, v] : adj[u])
        {
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}