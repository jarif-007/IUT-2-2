#include "bits/stdc++.h"
using namespace std;

bool hasCycle(vector<vector<int>> &adj_list, vector<bool> &visited, int start);

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj_list(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u--, v--;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (hasCycle(adj_list, visited, i))
                    ans++;
            }
        }

        cout << ans << endl;
    }
}

bool hasCycle(vector<vector<int>> &adj_list, vector<bool> &visited, int start)
{
    queue<pair<int, int>> q;

    visited[start] = true;
    q.push({start, -1});

    while (!q.empty())
    {
        auto [node, parent] = q.front();
        q.pop();

        for (int neighbor : adj_list[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, node});
            }

            else if (neighbor != parent)
                return true;
        }
    }

    return false;
}