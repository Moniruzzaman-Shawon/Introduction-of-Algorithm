#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int area = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int ci = current.first;
        int cj = current.second;
        area++;

        for (int i = 0; i < 4; i++) {
            int ni = ci + d[i].first;
            int nj = cj + d[i].second;

            if (valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] == '.') {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int minArea = INT_MAX;
    bool hasComponent = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                hasComponent = true;
                int area = bfs(i, j);
                if (area < minArea) {
                    minArea = area;
                }
            }
        }
    }

    if (hasComponent) {
        cout << minArea << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}