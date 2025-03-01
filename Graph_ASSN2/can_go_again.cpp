#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;
    Edge(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

const int INF = 1e9;
int n, e;
int dis[1005];  // Distance array
vector<Edge> edge_list;

bool bellmanFord(int s) {  
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[s] = 0;  

    // Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;
        for (auto ed : edge_list) {
            int a = ed.a, b = ed.b, c = ed.c;
            if (dis[a] != INF && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
                updated = true;
            }
        }
        if (!updated) break;  // Early termination
    }

    // Check for negative weight cycle
    for (auto ed : edge_list) {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != INF && dis[a] + c < dis[b]) {
            return false;  // Negative cycle detected
        }
    }

    return true;
}

int main() {
    cin >> n >> e;
    edge_list.clear();

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));  // Directed graph
    }

    int s;
    cin >> s;

    if (!bellmanFord(s)) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        if (dis[d] == INF) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[d] << endl;
        }
    }

    return 0;
}
