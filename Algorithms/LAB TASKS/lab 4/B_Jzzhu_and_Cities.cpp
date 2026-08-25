#include "bits/stdc++.h"
using namespace std;

int dijkstra(long long src, vector<vector<tuple<long long, long long, bool>>> &graph);

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    vector<vector<tuple<long long, long long, bool>>> graph(n);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;

        graph[u - 1].push_back({wt, v - 1, false});
        graph[v - 1].push_back({wt, u - 1, false});
    }

    for (long long i = 0; i < k; i++)
    {
        long long s, wt;
        cin >> s >> wt;

        graph[0].push_back({wt, s - 1, true});
        graph[s - 1].push_back({wt, 0, true});
    }

    int uses_train = dijkstra(0, graph);
    cout << k - uses_train << endl;
}

int dijkstra(long long src, vector<vector<tuple<long long, long long, bool>>> &graph)
{
    vector<long long> dist(graph.size(), LLONG_MAX);
    vector<bool> uses_train(graph.size(), false);

    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<>>
        pq;

    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (dist_u > dist[u])
            continue;

        for (auto &[wt, v, isTrain] : graph[u])
        {
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                uses_train[v] = isTrain;
                pq.push({dist[v], v});
            }
            else if (dist[u] + wt == dist[v] && uses_train[v] && !isTrain)
                uses_train[v] = false;
        }
    }

    int necessary_trains = 0;
    for (bool train_used : uses_train)
    {
        if (train_used)
            necessary_trains++;
    }

    return necessary_trains;
}