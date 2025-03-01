#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    // Initialize adjacency matrix with large values
    vector<vector<long long>> adj_mat(n, vector<long long>(n, 1e18));

    // Set diagonal to 0
    for (int i = 0; i < n; i++)
        adj_mat[i][i] = 0;

    // Read edges
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c; // Assuming directed graph
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {   
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < n; j++) {             
                if (adj_mat[i][k] != 1e18 && adj_mat[k][j] != 1e18)  
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);   
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_mat[i][j] == 1e18)
                cout << "INF ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
