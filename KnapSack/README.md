# 0-1 Knapsack Problem

## Description
The **0-1 Knapsack Problem** is a classic **dynamic programming** problem where we are given `n` items, each with a weight and a value. Our goal is to determine the maximum value we can obtain by selecting items such that their total weight does not exceed a given capacity. 

In the **0-1 knapsack**, each item can either be included **entirely** or **not included at all** (hence the "0-1" constraint).

## Problem Statement
Given:
- An integer `n` (number of items)
- Two arrays:
  - `val[i]`: Value of the `i-th` item
  - `weight[i]`: Weight of the `i-th` item
- An integer `max_weight` (maximum weight the knapsack can carry)

Find the maximum value we can obtain.

## Approach
This problem is solved using **recursion + memoization** (Top-Down Dynamic Programming). The function follows these rules:
1. If no items are left or max weight is `0`, return `0` (Base Case).
2. If the result for `dp[i][max_weight]` is already computed, return it (Memoization).
3. If `weight[i]` is less than or equal to `max_weight`, we have two choices:
   - Include the item and check for `knapsack(i-1, max_weight - weight[i]) + val[i]`.
   - Exclude the item and check for `knapsack(i-1, max_weight)`.
4. If `weight[i]` is greater than `max_weight`, we must exclude it.

The final result is stored in `dp[n-1][max_weight]`.

## Complexity Analysis
- **Time Complexity:** `O(n * max_weight)` due to memoization.
- **Space Complexity:** `O(n * max_weight)` for the `dp[][]` table.

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int max_weight) {
    if (i < 0 || max_weight <= 0)
        return 0;
    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    if (weight[i] <= max_weight) {
        int option1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int option2 = knapsack(i - 1, max_weight);
        dp[i][max_weight] = max(option1, option2);
    } else {
        dp[i][max_weight] = knapsack(i - 1, max_weight);
    }
    return dp[i][max_weight];
}

int main() {
    int n, max_weight;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {
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
```

## Example Input/Output
**Input:**
```
4
1 2 3 4
2 3 4 5
5
```
**Output:**
```
3
```

## Alternative Approaches
1. **Bottom-Up DP (Tabulation):** Instead of recursion, use an iterative table to store intermediate results.
2. **Space Optimization:** Use a 1D array instead of a 2D table to reduce space complexity to `O(max_weight)`.

## References
- [Knapsack Problem - GeeksforGeeks](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- [Dynamic Programming - MIT OpenCourseWare](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-notes/)

---
**Author:** Moniruzzaman Shawon
