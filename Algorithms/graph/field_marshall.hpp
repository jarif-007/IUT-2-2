#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> floyd_warshall(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        dist[u][v] = min(dist[u][v], wt);
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "neg cycle detected\n";
            return NULL;
        }
    }

    return dist;
}