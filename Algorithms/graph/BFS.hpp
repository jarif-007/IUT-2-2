#include "bits/stdc++.h"
using namespace std;

void helper_bfs(vector<vector<pair<int, int>>> &adj_list, int start, unordered_set<int> &visited)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int queue_front = q.front();
        q.pop();
        cout << queue_front << endl;

        vector<pair<int, int>> &neighbors = adj_list[queue_front];
        for (auto &[neighbor, weight] : neighbors)
        {
            if (!visited.contains(neighbor))
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

void BFS(vector<vector<pair<int, int>>> &adj_list)
{
    unordered_set<int> visited;
    for (int i = 0, v = adj_list.size(); i < v; i++)
    {
        if (!visited.contains(i))
            helper_bfs(adj_list, i, visited);
    }
}