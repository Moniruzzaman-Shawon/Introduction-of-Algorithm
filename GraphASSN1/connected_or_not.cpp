#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<unordered_set<int>> adj_list(n);
    
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].insert(b);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        if (a == b || adj_list[a].find(b) != adj_list[a].end()) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
