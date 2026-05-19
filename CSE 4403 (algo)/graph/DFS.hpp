#include "bits/stdc++.h"
using namespace std;

void helper_dfs(vector<vector<pair<int, int>>> &adj_list, int start, unordered_set<int> &visited)
{
    stack<int> st;
    st.push(start);
    visited.insert(start);

    while (!st.empty())
    {
        int stack_top = st.top();
        st.pop();

        cout << stack_top << endl;

        vector<pair<int, int>> &neighbors = adj_list[stack_top];
        for (auto &[neighbor, weight] : neighbors)
        {
            if (!visited.contains(neighbor))
            {
                visited.insert(neighbor);
                st.push(neighbor);
            }
        }
    }
}

void DFS(vector<vector<pair<int, int>>> &adj_list)
{
    unordered_set<int> visited;
    for (int i = 0, v = adj_list.size(); i < v; i++)
    {
        if (!visited.contains(i))
            helper_dfs(adj_list, i, visited);
    }
}