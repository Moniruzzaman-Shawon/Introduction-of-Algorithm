#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, int weight[], int val[]) {
    int dp[W+1] = {0};

    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + val[i]);
        }
    }
    return dp[W]; 
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N, W;
        cin >> N >> W;

        int weight[N], val[N];

        for (int i = 0; i < N; i++) {
            cin >> weight[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> val[i];
        }

        cout << knapsack(N, W, weight, val) << endl; 
    }

    return 0;
}
