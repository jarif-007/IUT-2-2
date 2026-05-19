#include "bits/stdc++.h"
using namespace std;

vector<int> bellman_ford(vector<tuple<int, int, int>> &edges, int source)
{
    int maxNode = 0;
    for (auto &[u, v, wt] : edges)
        maxNode = max(maxNode, max(u, v));

    vector<int> dist(maxNode + 1, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < maxNode; i++)
    {
        for (auto &[u, v, wt] : edges)
        {
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                if (i == v - 1)
                    return {-1};

                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}