#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(long long src, vector<vector<pair<long long, long long>>> &adj);

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;

        adj[u - 1].push_back({wt, v - 1});
    }

    long long src = 0;
    vector<long long> distances = dijkstra(src, adj);
    for (auto &distance : distances)
        cout << distance << " ";
}

vector<long long> dijkstra(long long src, vector<vector<pair<long long, long long>>> &adj)
{
    vector<long long> dist(adj.size(), LLONG_MAX);
    vector<bool> visited(adj.size());
    dist[src] = 0;

    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<>>
        pq;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        for (auto &[wt, v] : adj[u])
        {
            if (visited[v])
                continue;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}