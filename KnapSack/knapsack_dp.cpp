#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int max_weight) {    //complexity O(NW)
    // Base case
    if (i < 0 || max_weight <= 0)
        return 0;

    // Memoization check
    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    if (weight[i] <= max_weight) {
        // Two options: include or exclude item
        int option1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int option2 = knapsack(i - 1, max_weight);
        dp[i][max_weight] = max(option1, option2);
    } else {
        // Only one option: exclude item
        dp[i][max_weight] = knapsack(i - 1, max_weight);
    }
    return dp[i][max_weight];
}

int main() {
    int n, max_weight;
    cin >> n;  // Read 'n' before using it in the loop!

    // Initialize DP table properly
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {  // Assuming max weight <= 1000
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cin >> max_weight;

    cout << knapsack(n - 1, max_weight) << endl;
    return 0;
}
