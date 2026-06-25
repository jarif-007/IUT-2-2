#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj_list, int src)
{
    vector<int> dist(adj_list.size(), INT_MAX);
    unordered_set<int> marked;

    priority_queue<
        // (distance, node)
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        minHeap;

    dist[src] = 0;
    minHeap.push({dist[src], src});

    while (!minHeap.empty())
    {
        auto [dist_u, u] = minHeap.top();
        minHeap.pop();

        if (marked.contains(u))
            continue;

        marked.insert(u);

        for (auto &[v, wt] : adj_list[u])
        {
            if (marked.contains(v))
                continue;

            if (dist_u + wt < dist[v])
            {
                dist[v] = dist_u + wt;
                minHeap.push({dist[v], v});
            }
        }
    }

    return dist;
}