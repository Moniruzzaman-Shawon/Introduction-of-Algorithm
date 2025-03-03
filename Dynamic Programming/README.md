# Dynamic Programming (DP) in C++

## Overview
Dynamic Programming (DP) is an optimization technique used to solve problems by breaking them down into smaller overlapping subproblems and storing their results to avoid redundant computations.

### Key Concepts:
1. **Overlapping Subproblems** – The problem can be broken down into smaller subproblems that are solved multiple times.
2. **Optimal Substructure** – The optimal solution to a problem depends on the optimal solutions to its subproblems.

---

## DP Approaches
### **1. Top-Down (Memoization)**
Uses recursion and stores computed values in an array (or `map`) to avoid recomputation.

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(100, -1);

int fib(int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
```

### **2. Bottom-Up (Tabulation)**
Uses an iterative approach to fill a table and build up the solution from base cases.

```cpp
#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    int dp[n + 1];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
```

---

## Optimization Techniques in DP

### **1. Space Optimization**
Instead of storing all previous results, optimize space by keeping only the necessary values.

```cpp
#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1, curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
```

✅ **Space Complexity:** `O(1)` (instead of `O(n)`) 

---

### **2. State Reduction (Knapsack Problem Optimization)**
Instead of using a `dp[n][W]` table (`O(nW)` space), we use a **single array** (`O(W)` space).

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int W, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
        }
    }
    
    return dp[W];
}

int main() {
    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 20, 30};
    int W = 5;
    cout << "Max Value = " << knapsack(weight, value, W, weight.size()) << endl;
    return 0;
}
```

✅ **Space Complexity:** `O(W)` (instead of `O(nW)`) 

---

### **3. Faster Transition (Matrix Exponentiation for Fibonacci)**
Instead of `O(n)`, we reduce time complexity to `O(log n)` using matrix exponentiation.

```cpp
#include <iostream>
using namespace std;

void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x, F[0][1] = y;
    F[1][0] = z, F[1][1] = w;
}

void power(int F[2][2], int n) {
    if (n <= 1) return;
    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}

int fib(int n) {
    if (n <= 1) return n;
    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
```

✅ **Time Complexity:** `O(log n)`, much faster than `O(n)`

---

## Why Optimize DP?
- **Avoid TLE (Time Limit Exceeded)**
- **Reduce Memory Usage**
- **Handle Large Constraints Efficiently**

---

# Memoization in C++

## Why Optimization?

Consider an input **9**:
- Without optimization, it performs a lot of operations.
- Memoization reduces redundant calculations and improves performance.

---

## 🚀 Memoization in C++
Memoization is an **optimization technique** used to store results of **expensive function calls** and return the cached result when the same inputs occur again.  
It helps to avoid redundant calculations and speeds up recursive solutions.

### 🔹 Example: Fibonacci using Memoization
The **Fibonacci sequence** is a classic example where memoization helps to reduce `O(2ⁿ)` → `O(n)`.

---

### **❌ Without Memoization (Exponential Time)**
```cpp
#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(40); // Very slow for large n
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(100, -1); // Memoization array initialized with -1

int fib(int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n]; // Return cached result
    return dp[n] = fib(n - 1) + fib(n - 2); // Store result
}

int main() {
    cout << fib(40); // Now runs in O(n)
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

long long int dp[1005]; // For large numbers

long long int fibonacci(int n) { // Complexity O(N)
    if (n == 0 || n == 1)  
        return n;

    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof(dp));
    long long int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}



### 📌 How to Use:
- Save this content as `README.md` in your GitHub repository.
- It includes formatted markdown with proper **code blocks, explanations, and complexity analysis**.
- Looks great in GitHub and is easy to read!

Let me know if you need any modifications! 🚀
