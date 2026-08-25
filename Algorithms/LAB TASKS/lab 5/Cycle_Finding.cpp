#include "bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int cycle_start = -1;
    for (int i = 0; i < n; i++)
    {
        for (auto &[u, v, wt] : edges)
        {
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;

                if (i == n - 1)
                    cycle_start = v;
            }
        }
    }

    if (cycle_start == -1)
        cout << "NO\n";

    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cycle_start = parent[cycle_start];

        int curr = cycle_start;
        vector<int> cycle;

        do
        {
            cycle.push_back(curr);
            curr = parent[curr];
        } while (curr != cycle_start);

        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
            cout << node << " ";

        cout << endl;
    }
}