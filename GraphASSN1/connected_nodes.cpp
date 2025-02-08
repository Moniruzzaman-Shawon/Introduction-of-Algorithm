#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj_list(n);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--) {
        int node;
        cin >> node;

        if (adj_list[node].empty()) {
            cout << "-1" << endl;
        } else {
            sort(adj_list[node].rbegin(), adj_list[node].rend());
            for (int x : adj_list[node]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
