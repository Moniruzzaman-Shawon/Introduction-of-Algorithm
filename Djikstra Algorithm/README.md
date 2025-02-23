# Dijkstra's Algorithm 🚀  

## **Overview**  
Dijkstra's Algorithm is used to find the shortest path from a **single source node** to all other nodes in a weighted graph (with non-negative weights).  

## **Time Complexity Analysis**  
- **Priority Queue Operations** (Push/Pop) → `O(log V)`  
- **Total Complexity Calculation**:  
  - \( O((E + V) \log V) \)  
  - Since \( E \geq V \), we approximate:  
    - \( O((E + E) \log V) = O(2E \log V) \)  
  - Removing constants → **\( O(E \log V) \)**  

## **C++ Implementation**  
```cpp
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Dijkstra's Algorithm using Priority Queue (Min-Heap)
void dijkstra(int V, vector<pair<int, int>> adj[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);

    dist[src] = 0;
    pq.push({0, src}); // (distance, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // Ignore outdated distances

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from source
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance: " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> adj[V];

    // Example graph (undirected)
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}




---

Let me know if you need any modifications! 😊

