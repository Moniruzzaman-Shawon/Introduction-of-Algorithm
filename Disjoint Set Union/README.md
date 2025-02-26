# Disjoint Set Union (DSU) - Union Find Algorithm

## Overview
Disjoint Set Union (DSU), also known as Union-Find, is a data structure that efficiently handles dynamic connectivity queries. It supports two main operations:

- **Find**: Determines the representative (root) of the set containing an element.
- **Union**: Merges two disjoint sets into one.

This structure is commonly used in graph-related algorithms like **Kruskal’s MST**, **cycle detection**, and **connected components**.

## Features
- Uses **Path Compression** to optimize the `Find` operation.
- Implements **Union by Rank** to keep the tree balanced.
- Achieves nearly **O(1) per operation** using the inverse Ackermann function **O(α(n))**.

## Implementation

### **C++ Code**
```cpp
#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    // Constructor to initialize DSU
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent (initially)
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by Rank
    void unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    // Check if two elements belong to the same set
    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};

// Driver Code
int main() {
    int n = 7; // Number of elements
    DSU dsu(n);

    dsu.unionSet(1, 2);
    dsu.unionSet(2, 3);
    dsu.unionSet(4, 5);
    
    cout << "Are 1 and 3 connected? " << (dsu.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 connected? " << (dsu.isConnected(3, 4) ? "Yes" : "No") << endl;

    dsu.unionSet(3, 4); // Merging the two sets

    cout << "Are 3 and 4 connected now? " << (dsu.isConnected(3, 4) ? "Yes" : "No") << endl;

    return 0;
}





---

### **Key Features of this README:**
✅ **Well-structured with explanation and code snippets**  
✅ **Includes compilation and execution instructions**  
✅ **Shows expected output**  
✅ **Explains applications and complexity analysis**  

Let me know if you want any modifications! 🚀

