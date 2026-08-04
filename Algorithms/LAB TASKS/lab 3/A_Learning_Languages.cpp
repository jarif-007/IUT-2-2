#include "bits/stdc++.h"
using namespace std;

class DSU
{
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int a)
    {
        while (parent[a] != a)
            a = parent[a];

        return a;
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB)
            parent[rootA] = rootB;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> list(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int count;
        cin >> count;

        for (int j = 1; j <= count; j++)
        {
            int language;
            cin >> language;

            list[i].push_back(language);
        }
    }
}