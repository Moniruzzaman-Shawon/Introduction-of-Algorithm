#include <bits/stdc++.h>
using namespace std;

// Possible knight moves
vector<pair<int, int>> knight_moves = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};

int minKnightMoves(int n, int m, int kx, int ky, int qx, int qy) {
    if (kx == qx && ky == qy) return 0;  // Knight is already at queen's position

    queue<pair<int, int>> q;
    map<pair<int, int>, int> visited;  // To track visited positions and steps

    q.push({kx, ky});
    visited[{kx, ky}] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        int steps = visited[{x, y}];
        q.pop();

        for (auto [dx, dy] : knight_moves) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited.find({nx, ny}) == visited.end()) {
                if (nx == qx && ny == qy) return steps + 1;  // Found queen
                q.push({nx, ny});
                visited[{nx, ny}] = steps + 1;
            }
        }
    }

    return -1;  // Queen is not reachable
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n, m, kx, ky, qx, qy;
        cin >> n >> m >> kx >> ky >> qx >> qy;
        cout << minKnightMoves(n, m, kx, ky, qx, qy) << endl;
    }

    return 0;
}
