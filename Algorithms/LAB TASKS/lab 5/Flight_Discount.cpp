#include "bits/stdc++.h"
using namespace std;

const long long INF = 1e17;

vector<long long> path_dijkstra(long long src, vector<vector<pair<long long, long long>>> &graph);

int main(void)
{
    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> graph(n);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;

        graph[u - 1].push_back({wt, v - 1});
    }

    vector<long long> path = path_dijkstra(0, graph);
    long long max_idx = 0;

    for (long long i = 1; i < path.size(); i++)
    {
        if (path[i] > path[max_idx])
            max_idx = i;
    }

    path[max_idx] /= 2;

    long long sum = 0;
    for (auto node : path)
        sum += node;

    cout << sum << endl;
}

vector<long long> path_dijkstra(long long src, vector<vector<pair<long long, long long>>> &graph)
{
    long long n = graph.size();

    vector<long long> dist(n, INF);
    vector<long long> parent(n, -1);
    vector<bool> marked(n, false);

    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<>>
        pq;

    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (marked[u])
            continue;

        marked[u] = true;
        for (auto &[wt, v] : graph[u])
        {
            if (marked[v])
                continue;

            if (dist_u + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<long long> path;
    long long curr = n - 1;

    while (parent[curr] != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    return path;
}