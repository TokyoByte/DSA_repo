#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir[] = {"up", "down", "left", "right"};

struct Node {
    int x, y;
};

bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0 && !visited[x][y]);
}

int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid values (0 = open, 1 = blocked):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
        cout << "-1" << endl;
        return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<string>> moveDir(n, vector<string>(m, ""));

    queue<Node> q;
    q.push({0, 0});
    visited[0][0] = true;

    bool found = false;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == n-1 && cur.y == m-1) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (isValid(nx, ny, n, m, grid, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {cur.x, cur.y};
                moveDir[nx][ny] = dir[k];
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "-1" << endl;
        return 0;
    }

    // Reconstruct path
    vector<string> path;
    int x = n - 1, y = m - 1;

    while (!(x == 0 && y == 0)) {
        path.push_back(moveDir[x][y]);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    reverse(path.begin(), path.end());

    cout << "Path Length: " << path.size() << endl;
    cout << "Sequence of movement: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << ",";
    }
    cout << endl;

    return 0;
}
