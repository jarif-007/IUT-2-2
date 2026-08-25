#include "bits/stdc++.h"
using namespace std;

void DFS(int curr, int parent, vector<vector<int>> &graph, vector<int> &cats, int &valid_restaurants, int consecutive_cats, int limit);

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> cats(n);
    for (int i = 0; i < n; i++)
        cin >> cats[i];

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int valid_restaurants = 0;
    int consecutive_cats = 0;

    DFS(0, -1, graph, cats, valid_restaurants, consecutive_cats, m);
    cout << valid_restaurants << endl;
}

void DFS(int curr, int parent, vector<vector<int>> &graph, vector<int> &cats, int &valid_restaurants, int consecutive_cats, int limit)
{
    consecutive_cats = cats[curr] == 1 ? consecutive_cats + 1 : 0;
    if (consecutive_cats > limit)
        return;

    bool is_leaf = true;
    for (auto neighbor : graph[curr])
    {
        if (neighbor != parent)
        {
            is_leaf = false;
            DFS(neighbor, curr, graph, cats, valid_restaurants, consecutive_cats, limit);
        }
    }

    if (is_leaf)
        valid_restaurants++;
}