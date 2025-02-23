# 🚀 Floyd-Warshall Algorithm

The **Floyd-Warshall Algorithm** is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It works for both **directed and undirected graphs** and supports **negative edge weights** (but no negative cycles).

## 🔍 **Algorithm Overview**
- The algorithm maintains a **distance matrix** `dist[][]`, where `dist[i][j]` represents the shortest distance from vertex `i` to vertex `j`.
- It iterates through all vertices, using each as an **intermediate node** to update the shortest paths.

## 🔢 **Steps**
1. **Initialize `dist[][]`:**
   - `dist[i][j] = weight(i, j)`, if there is an edge from `i` to `j`.
   - `dist[i][i] = 0` (distance from a node to itself).
   - `dist[i][j] = ∞` (if no edge exists between `i` and `j`).

2. **Update distances using:**
   \[
   dist[i][j] = \min(dist[i][j], dist[i][k] + dist[k][j])
   \]
   where `k` is an intermediate vertex.

## ⏳ **Complexity Analysis**
- **Time Complexity:** `O(V³)` (due to three nested loops).
- **Space Complexity:** `O(V²)` (for storing the distance matrix).

## 🔗 **Example Graph**
Given a weighted graph:

|   | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 3 | ∞ | 7 |
| B | 8 | 0 | 2 | ∞ |
| C | 5 | ∞ | 0 | 1 |
| D | 2 | ∞ | ∞ | 0 |

After applying the **Floyd-Warshall Algorithm**, the shortest path matrix will be:

|   | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 3 | 5 | 6 |
| B | 5 | 0 | 2 | 3 |
| C | 3 | 6 | 0 | 1 |
| D | 2 | 5 | 7 | 0 |

## 💻 **C++ Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(dist, V);

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
