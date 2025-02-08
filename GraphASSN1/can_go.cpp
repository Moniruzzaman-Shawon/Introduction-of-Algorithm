#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> building;
bool vis[1005][1005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    vis[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
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
