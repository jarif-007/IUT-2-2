#include "bits/stdc++.h"
using namespace std;

// for unweighted, force weight = constant value
vector<vector<pair<int, int>>> adj_list(vector<tuple<int, int, int>> edges)
{
    int maxNode = 0;
    for (auto &edge : edges)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);

        maxNode = max(maxNode, max(u, v));
    }

    vector<vector<pair<int, int>>> adj_list(maxNode + 1);
    for (auto &edge : edges)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w}); // for undirected
    }

    return adj_list;
}