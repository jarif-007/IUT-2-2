#include "bits/stdc++.h"
using namespace std;

class DSU
{
public:
    vector<long long> parent;

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

int main(void)
{
    long long n, m;
    cin >> n >> m;

    vector<vector<long long>> edges(m, vector<long long>(2, 0));
    DSU dsu(n);

    for (long long i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        dsu.unite(edges[i][0], edges[i][1]);
    }

    vector<int> ans;
    for (int i = 1; i < dsu.parent.size(); i++)
    {
        if (dsu.find(i) == i)
            ans.push_back(dsu.parent[i]);
    }

    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i - 1] << " " << ans[i] << endl;
}
