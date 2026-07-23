#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> getNeighbors(int x, int y, vector<vector<char>> &grid);
bool valid_index(int x, int y, vector<vector<char>> &grid);

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == '#')
                visited[i][j] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            queue<pair<int, int>> queue;
            if (!visited[i][j])
            {
                visited[i][j] = true;
                queue.push({i, j});
                count++;
            }

            while (!queue.empty())
            {
                auto [a, b] = queue.front();
                queue.pop();

                vector<pair<int, int>> neighbors = getNeighbors(a, b, grid);
                for (auto &[x, y] : neighbors)
                {
                    if (!visited[x][y])
                    {
                        visited[x][y] = true;
                        queue.push({x, y});
                    }
                }
            }
        }
    }

    cout << count << endl;
}

vector<pair<int, int>> getNeighbors(int x, int y, vector<vector<char>> &grid)
{
    vector<pair<int, int>> neighbors;
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto &[dx, dy] : directions)
    {
        int nx = x + dx;
        int ny = y + dy;

        if (valid_index(nx, ny, grid))
            neighbors.push_back({nx, ny});
    }

    return neighbors;
}

bool valid_index(int x, int y, vector<vector<char>> &grid)
{
    bool valid_x = x >= 0 && x < grid.size();
    bool valid_y = y >= 0 && y < grid[0].size();

    return valid_x && valid_y;
}