#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    pair<int, int> src, dest;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                src = {i, j};

            if (grid[i][j] == 'B')
                dest = {i, j};
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    char direction[] = {'L', 'R', 'U', 'D'};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> action(n, vector<char>(m, '\0'));

    queue<pair<int, int>> q;
    q.push({src.first, src.second});
    visited[src.first][src.second] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == dest.first && y == dest.second)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            else if (grid[nx][ny] == '#')
                continue;

            else if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            parent[nx][ny] = {x, y};
            action[nx][ny] = direction[i];
            q.push({nx, ny});
        }
    }

    if (!visited[dest.first][dest.second])
    {
        cout << "NO\n";
        return 0;
    }

    string path = "";
    pair<int, int> curr = dest;
    while (!(curr.first == src.first && curr.second == src.second))
    {
        path += action[curr.first][curr.second];
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << endl;
    cout << path << endl;
}