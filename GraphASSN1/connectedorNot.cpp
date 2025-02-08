#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

int main() {
    int n, e;
    cin >> n >> e;
    
    // Reading the edges to form the graph
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // Directed edge from a to b
    }
    
    // Number of queries
    int q;
    cin >> q;
    
    // Process each query
    while (q--) {
        int src, dst;
        cin >> src >> dst;

        // Check if there is a direct edge from src to dst
        bool found = false;
        for (int child : adj_list[src]) {
            if (child == dst) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}