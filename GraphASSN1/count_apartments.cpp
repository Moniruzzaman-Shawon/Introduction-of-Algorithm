#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> building;
bool visited[1005][1005];

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (auto dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && building[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    building.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }
    
    memset(visited, false, sizeof(visited));
    
    int apartment_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                apartment_count++;
            }
        }
    }
    
    cout << apartment_count << endl;
    return 0;
}
