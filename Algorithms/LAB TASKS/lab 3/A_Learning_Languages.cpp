#include "bits/stdc++.h"
using namespace std;

void BFS(int src, vector<vector<int>> &graph, set<int> &visited);

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> list(n);
    for (int i = 0; i < n; i++)
    {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++)
        {
            int lang;
            cin >> lang;

            list[i].push_back(lang - 1);
        }
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            auto &list_i = list[i];
            auto &list_j = list[j];

            bool hit = false;
            for (auto item_i : list_i)
            {
                for (auto item_j : list[j])
                {

                    if (item_i == item_j)
                    {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                        hit = true;
                        break;
                    }
                }

                if (hit)
                    break;
            }
        }
    }

    int non_zero = 0, zero = 0;
    set<int> visited;

    for (int i = 0; i < n; i++)
    {
        if (visited.count(i))
            continue;

        BFS(i, graph, visited);
        list[i].size() == 0 ? zero++ : non_zero++;
    }

    int ans = non_zero == 0 ? zero : zero + non_zero - 1;
    cout << ans << endl;
}

void BFS(int src, vector<vector<int>> &graph, set<int> &visited)
{
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (visited.count(curr))
            continue;

        visited.insert(curr);
        for (auto &neighbor : graph[curr])
        {
            if (visited.count(neighbor))
                continue;

            q.push(neighbor);
        }
    }
}