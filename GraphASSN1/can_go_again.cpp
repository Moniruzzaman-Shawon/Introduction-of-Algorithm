#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> building;
bool vis[1005][1005];

// Directions in a vector of pairs (dx, dy)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
    vis[x][y] = true;
    
    for (auto dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
            (building[nx][ny] == '.' || building[nx][ny] == 'B')) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    building.resize(n);
    
    pair<int, int> A, B;
    
    for (int i = 0; i < n; i++) {
        cin >> building[i];
        for (int j = 0; j < m; j++) {
            if (building[i][j] == 'A') {
                A = {i, j};
            } else if (building[i][j] == 'B') {
                B = {i, j};
            }
        }
    }
    
    memset(vis, false, sizeof(vis));
    dfs(A.first, A.second);
    
    if (vis[B.first][B.second]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
