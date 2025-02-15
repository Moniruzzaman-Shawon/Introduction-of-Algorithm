#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int di, dj;
bool found = false;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int ci = current.first;
        int cj = current.second;

        if (ci == di && cj == dj) {
            found = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ni = ci + d[i].first;
            int nj = cj + d[i].second;

            if (valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] == '.') {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj >> di >> dj;

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}