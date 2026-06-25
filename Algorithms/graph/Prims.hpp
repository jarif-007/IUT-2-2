#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int, int>>> &adj_list, int src)
{
    int V = adj_list.size();

    vector<int> cost(V, INT_MAX);
    unordered_set<int> marked;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    cost[src] = 0;
    minHeap.push({cost[src], src});

    int ans = 0;
    while (!minHeap.empty())
    {
        auto [dist_u, u] = minHeap.top();
        minHeap.pop();

        if (marked.count(u))
            continue;

        marked.insert(u);
        ans += dist_u;

        for (auto &[v, wt] : adj_list[u])
        {
            if (marked.contains(v))
                continue;

            if (wt < cost[v])
            {
                cost[v] = wt;
                minHeap.push({wt, v});
            }
        }
    }

    return ans;
}