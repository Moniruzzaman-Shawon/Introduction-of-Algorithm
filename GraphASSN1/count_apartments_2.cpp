#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> building;
bool visited[1005][1005];

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int& count) {
    visited[x][y] = true;
    count++;
    
    for (auto dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && building[nx][ny] == '.') {
            dfs(nx, ny, count);
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
    
    vector<int> room_counts;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] == '.' && !visited[i][j]) {
                int room_count = 0;
                dfs(i, j, room_count);
                room_counts.push_back(room_count);
            }
        }
    }
    
    if (room_counts.empty()) {
        cout << "-1" << endl;
    } else {
        sort(room_counts.begin(), room_counts.end());
        for (int count : room_counts) {
            cout << count << " ";
        }
        cout << endl;
    }
    
    return 0;
}
