# Bellman-Ford Algorithm

## 📌 Overview
The **Bellman-Ford Algorithm** is a **single-source shortest path algorithm** that finds the shortest paths from a given source vertex to all other vertices in a **weighted graph**. Unlike Dijkstra’s algorithm, Bellman-Ford can handle graphs with **negative weight edges** and can detect **negative weight cycles**.

## 🛠️ When to Use Bellman-Ford?
| **Scenario** | **Bellman-Ford?** |
|-------------|----------------|
| Graph has **negative weight edges** | ✅ Yes |
| Graph has **negative weight cycles** | ✅ Yes (to detect them) |
| Graph is **dense (many edges)** | ❌ No (Dijkstra is better) |
| Need **shortest path from a single source** | ✅ Yes |
| Need **all-pairs shortest paths** | ❌ No (Use Floyd-Warshall) |

---

## 🔍 Algorithm Steps
1. **Initialize distances**:
   - Set the distance of the **source vertex** to 0.
   - Set the distance of all other vertices to **infinity (∞)**.

2. **Relax all edges (V - 1 times)**:
   - For each edge (u, v) with weight `w`, update the distance to `v` if a shorter path is found:
     ```
     if d[u] + w < d[v] then update d[v] = d[u] + w
     ```

3. **Detect negative cycles**:
   - Perform one more pass over all edges.
   - If any distance updates happen, there is a **negative weight cycle**.

---

## 📝 Pseudocode
```python
# Bellman-Ford Algorithm in Python
def bellman_ford(graph, V, E, source):
    distance = [float('inf')] * V
    distance[source] = 0

    for _ in range(V - 1):
        for u, v, w in graph:  # graph contains edges (u, v, w)
            if distance[u] != float('inf') and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    for u, v, w in graph:
        if distance[u] != float('inf') and distance[u] + w < distance[v]:
            print("Graph contains a negative weight cycle")
            return

    print("Vertex Distance from Source")
    for i in range(V):
        print(f"{i}: {distance[i]}")
```

---

## ⏳ Time Complexity
- **Best Case:** `O(V + E)` (with early termination)
- **Worst Case:** `O(V × E)`

| **Graph Type** | **Time Complexity** |
|--------------|----------------|
| Sparse Graph (E ≈ V) | `O(V²)` |
| Dense Graph (E ≈ V²) | `O(V³)` |

> **Compared to Dijkstra:**
> - Dijkstra’s **O((V + E) log V)** is **faster** but doesn’t work for **negative weights**.
> - Bellman-Ford is **slower** but **more flexible**.

---

## ✅ Advantages
✔ Works for graphs with **negative weight edges**.  
✔ Can **detect negative weight cycles**.  
✔ Simpler to implement than Dijkstra’s Algorithm.  
✔ Works for both **directed & undirected graphs**.

## ❌ Disadvantages
✘ **Slower** than Dijkstra’s algorithm for large graphs.  
✘ Takes `O(V × E)` time, which is inefficient for large graphs.  
✘ Does not work for **undirected graphs with negative weight cycles**.

---

## 🚀 Applications of Bellman-Ford
🔹 **Network Routing Protocols (e.g., Distance Vector Routing in RIP protocol)**  
🔹 **Currency Arbitrage (Detecting profitable currency exchange cycles)**  
🔹 **Detecting Negative Cycles in Financial Markets**  
🔹 **Evaluating Shortest Paths in Road Networks (with tolls & penalties)**  

---

## 🔎 Comparison with Dijkstra’s Algorithm
| **Feature** | **Bellman-Ford** | **Dijkstra** |
|------------|---------------|------------|
| **Handles Negative Weights?** | ✅ Yes | ❌ No |
| **Handles Negative Cycles?** | ✅ Yes (detects) | ❌ No |
| **Time Complexity** | `O(V × E)` | `O((V + E) log V)` |
| **Graph Type** | Works for all graphs | Works only for graphs with non-negative weights |
| **Faster for Sparse Graphs?** | ❌ No | ✅ Yes |
| **Faster for Dense Graphs?** | ❌ No | ✅ Yes |

---

## 🏁 Summary
- Bellman-Ford is **slower** but more **versatile** than Dijkstra’s algorithm.
- Best suited when **negative weight edges** exist.
- If negative cycles exist, it **detects them**.
- Used in **network routing**, **currency exchange**, and **graph cycle detection**.

---

## 📂 Repository Structure
```
📂 Bellman-Ford Algorithm
├── 📜 README.md  # Documentation
├── 📜 bellman_ford.py  # Python Implementation
└── 📂 examples  # Sample Graphs & Test Cases
```

---

## 💡 Contributing
Feel free to contribute by submitting issues or pull requests! 🚀

---

MIT License

Copyright (c) [2025] [Moniruzzaman Shawon]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


---

## 🙌 Acknowledgements
Special thanks to all the contributors and open-source developers. 💖
