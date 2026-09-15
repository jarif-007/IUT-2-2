#include "bits/stdc++.h"
using namespace std;

int main()
{

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n + 1);
    vector<vector<long long>> capacity(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;

        if (capacity[u][v] == 0 && capacity[v][u] == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        capacity[u][v] += c;
    }

    long long max_flow = 0;
    vector<int> parent(n + 1);

    while (true)
    {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2; // Mark source as visited

        // Queue stores pairs of {current_node, bottleneck_flow_so_far}
        queue<pair<int, long long>> q;
        q.push({s, 1e18});
        long long new_flow = 0;

        // BFS to find the shortest augmenting path
        while (!q.empty())
        {
            int cur = q.front().first;
            long long flow = q.front().second;
            q.pop();

            for (int next : adj[cur])
            {
                // If unvisited and there is available capacity
                if (parent[next] == -1 && capacity[cur][next] > 0)
                {
                    parent[next] = cur; // Record path
                    long long current_min_flow = min(flow, capacity[cur][next]);

                    if (next == t)
                    {
                        new_flow = current_min_flow; // Reached the target tank
                        break;
                    }
                    q.push({next, current_min_flow});
                }
            }
            if (new_flow > 0)
                break; // Break out of BFS if we reached the sink
        }

        // If no augmenting path was found, the maximum flow is reached
        if (new_flow == 0)
            break;

        max_flow += new_flow;
        int cur = t;

        // Backtrack from sink to source to update residual capacities
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow; // Forward edge capacity decreases
            capacity[cur][prev] += new_flow; // Reverse (residual) edge capacity increases
            cur = prev;
        }
    }

    cout << max_flow << endl;
}