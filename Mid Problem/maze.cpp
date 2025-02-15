#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];

int n, m, startX, startY, endX, endY;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !vis[i][j];
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == endX && y == endY) {
            return;
        }

        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
            }
        }
    }
}

void markPath() {
    int x = endX, y = endY;

    while (parent[x][y] != make_pair(-1, -1)) {
        auto [px, py] = parent[x][y];
        if (grid[px][py] != 'R') {
            grid[px][py] = 'X';
        }
        x = px;
        y = py;
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                startX = i, startY = j;
            } else if (grid[i][j] == 'D') {
                endX = i, endY = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(startX, startY);

    if (vis[endX][endY]) {
        markPath();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
