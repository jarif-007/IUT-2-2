#include "bits/stdc++.h"
using namespace std;

struct Cell
{
    int dist;
    bool mark;
};

void BFS(vector<vector<Cell>> &grid, pair<int, int> src);
vector<pair<int, int>> getNeighbors(vector<vector<Cell>> &grid, pair<int, int> node);
bool isValidNode(vector<vector<Cell>> &grid, pair<int, int> node);

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<vector<Cell>> grid(n, vector<Cell>(m));
        pair<int, int> src = {-1, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 'Z')
                {
                    grid[i][j].dist = 0;
                    grid[i][j].mark = true;

                    src = {i, j};
                }

                else if (arr[i][j] == '#')
                    grid[i][j].dist = -1,
                    grid[i][j].mark = true;

                else
                    grid[i][j].dist = -1,
                    grid[i][j].mark = false;
            }
        }

        BFS(grid, src);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << grid[i][j].dist << " ";

            cout << endl;
        }
    }
}

void BFS(vector<vector<Cell>> &grid, pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        int currDist = grid[a][b].dist;
        auto neighbors = getNeighbors(grid, {a, b});

        for (auto &[x, y] : neighbors)
        {
            if (!grid[x][y].mark)
            {
                grid[x][y].dist = currDist + 1;
                grid[x][y].mark = true;
                q.push({x, y});
            }
        }
    }
}

vector<pair<int, int>> getNeighbors(vector<vector<Cell>> &grid, pair<int, int> node)
{
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<pair<int, int>> neighbors;

    for (auto &[x, y] : directions)
    {
        auto potential_neighbor = make_pair(node.first + x, node.second + y);
        if (isValidNode(grid, potential_neighbor))
            neighbors.push_back(potential_neighbor);
    }

    return neighbors;
}

bool isValidNode(vector<vector<Cell>> &grid, pair<int, int> node)
{
    int x = node.first;
    int y = node.second;

    if (x < 0 || x >= grid.size())
        return false;

    if (y < 0 || y >= grid[0].size())
        return false;

    return true;
}