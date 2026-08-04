#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> &adj_list, vector<bool> &visited);

int main()
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

    vector<int> ans;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i, adj_list, visited);
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i - 1] + 1 << " " << ans[i] + 1 << endl;
}

void bfs(int src, vector<vector<int>> &adj_list, vector<bool> &visited)
{
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (visited[curr])
            continue;

        visited[curr] = true;
        for (int neighbor : adj_list[curr])
        {
            if (visited[neighbor])
                continue;

            q.push(neighbor);
        }
    }
}