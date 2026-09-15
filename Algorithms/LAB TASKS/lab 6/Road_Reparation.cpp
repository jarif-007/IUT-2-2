#include "bits/stdc++.h"
using namespace std;

class DSU
{
private:
    vector<long long> parent;

public:
    DSU(long long n)
    {
        parent.resize(n + 1);
        for (long long i = 1; i <= n; i++)
            parent[i] = i;
    }

    long long find(long long v)
    {
        if (parent[v] == v)
            return v;

        return parent[v] = find(parent[v]);
    }

    void unite(long long a, long long b)
    {
        long long root_a = find(a);
        long long root_b = find(b);

        if (root_a != root_b)
            parent[root_b] = root_a;
    }
};

bool compare(const vector<long long> &e1, const vector<long long> &e2)
{
    return e1[2] < e2[2];
}

int main(void)
{
    long long n, m;
    cin >> n >> m;

    vector<vector<long long>> edges(m, vector<long long>(3, 0));
    for (long long i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    sort(edges.begin(), edges.end(), compare);

    DSU dsu(n);
    long long edges_used = 0;
    long long cost = 0;

    for (auto edge : edges)
    {
        long long u = edge[0];
        long long v = edge[1];
        long long wt = edge[2];

        if (dsu.find(u) != dsu.find(v))
        {
            cost += wt;
            edges_used++;
            dsu.unite(u, v);
        }

        if (edges_used == n - 1)
        {
            break;
        }
    }

    if (edges_used == n - 1)
        cout << cost << endl;
    else
        cout << "IMPOSSIBLE\n";
}
