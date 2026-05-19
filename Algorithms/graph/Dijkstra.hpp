#include "bits/stdc++.h"
using namespace std;

struct DijkstraRow
{
    bool known;
    int dist;
    int parent;
};

vector<DijkstraRow> dijkstra(vector<vector<pair<int, int>>> &adj_list, int source)
{
    int v = adj_list.size();

    vector<DijkstraRow> table(v, {false, INT_MAX, -1});
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        minHeap;

    table[source].dist = 0;
    minHeap.push({0, source});

    while (!minHeap.empty())
    {
        auto [currDist, currNode] = minHeap.top();
        minHeap.pop();

        if (table[currNode].known)
            continue;

        table[currNode].known = true;
        auto &neighbors = adj_list[currNode];

        for (auto &[neighbor, weight] : neighbors)
        {
            auto &neighbor_info = table[neighbor];
            if (!neighbor_info.known && currDist + weight < neighbor_info.dist)
            {
                neighbor_info.dist = currDist + weight;
                neighbor_info.parent = currNode;

                minHeap.push({neighbor_info.dist, neighbor});
            }
        }
    }

    return table;
}