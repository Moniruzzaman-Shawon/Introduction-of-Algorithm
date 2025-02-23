# 🔍 Graph Algorithms: DFS vs BFS vs Dijkstra vs Bellman-Ford vs Floyd-Warshall

This repository contains a comparison of **DFS**, **BFS**, **Dijkstra**, **Bellman-Ford**, and **Floyd-Warshall** algorithms, their applications, time complexities, and when to use them.

---

## 📌 **1. Depth-First Search (DFS)**
✅ **Purpose**: Used for **graph traversal** (explores as deep as possible before backtracking).  
✅ **Type**: Unweighted traversal algorithm.  
✅ **Works on**: Both **directed and undirected graphs**.  

### **Approach**
- Uses **recursion (or a stack)** to explore a path **deeply** before moving to another.
- Common applications:
  - **Cycle detection**
  - **Connected components**
  - **Topological sorting**

### **Complexity**
| Case | Complexity |
|------|------------|
| **Time Complexity** | O(V + E) |
| **Space Complexity** | O(V) |

---

## 📌 **2. Breadth-First Search (BFS)**
✅ **Purpose**: Used for **graph traversal** (explores level by level).  
✅ **Type**: Unweighted traversal algorithm.  
✅ **Works on**: Both **directed and undirected graphs**.  

### **Approach**
- Uses a **queue** to explore all **neighbors** of a node before moving deeper.
- Common applications:
  - **Finding shortest paths in unweighted graphs**
  - **Connected components in an undirected graph**

### **Complexity**
| Case | Complexity |
|------|------------|
| **Time Complexity** | O(V + E) |
| **Space Complexity** | O(V) |

---

## 📌 **3. Dijkstra's Algorithm**
✅ **Purpose**: Finds the **shortest path from a single source** in a weighted graph (no negative weights).  
✅ **Type**: Greedy Algorithm.  
✅ **Works on**: **Directed & undirected graphs** with **non-negative weights**.  

### **Approach**
- Uses a **priority queue (min-heap)** to always expand the **shortest known path**.  
- Used in:
  - **Google Maps**
  - **Network routing**
  - **AI pathfinding**

### **Complexity**
| Case | Complexity |
|------|------------|
| **Time Complexity** | O((V + E) log V) |
| **Space Complexity** | O(V) |

---

## 📌 **4. Bellman-Ford Algorithm**
✅ **Purpose**: Finds the **shortest path from a single source**, even if **negative weights** exist.  
✅ **Type**: Dynamic Programming.  
✅ **Works on**: **Directed & undirected graphs** with **negative weights**.  

### **Approach**
- Iterates **V-1 times** over all edges to relax distances.
- Can detect **negative weight cycles**.

### **Complexity**
| Case | Complexity |
|------|------------|
| **Time Complexity** | O(V × E) |
| **Space Complexity** | O(V) |

---

## 📌 **5. Floyd-Warshall Algorithm**
✅ **Purpose**: Finds the **shortest path between all pairs of vertices**.  
✅ **Type**: Dynamic Programming.  
✅ **Works on**: **All types of graphs**, including **negative weights** (but no negative cycles).  

### **Approach**
- Uses a **distance matrix** and iteratively updates shortest paths.
- Suitable for **dense graphs**.

### **Complexity**
| Case | Complexity |
|------|------------|
| **Time Complexity** | O(V³) |
| **Space Complexity** | O(V²) |

---

## 📊 **Comparison Table**
| Algorithm        | Purpose                                    | Works on                | Handles Negative Weights? | Time Complexity |
|-----------------|-------------------------------------------|-------------------------|--------------------------|----------------|
| **DFS**         | Graph traversal (deep-first)             | Unweighted graphs       | ❌ No                    | O(V + E) |
| **BFS**         | Graph traversal (level-order)            | Unweighted graphs       | ❌ No                    | O(V + E) |
| **Dijkstra**    | Single-source shortest path              | Weighted graphs (no negative) | ❌ No            | O((V + E) log V) |
| **Bellman-Ford**| Single-source shortest path (negative weights) | Weighted graphs         | ✅ Yes                   | O(V × E) |
| **Floyd-Warshall** | All-pairs shortest paths               | Weighted graphs         | ✅ Yes                   | O(V³) |

---

## 🛠️ **When to Use Which Algorithm?**
- **DFS** → When you need to **explore paths deeply** (e.g., cycle detection, connected components).  
- **BFS** → When you need **shortest paths in an unweighted graph**.  
- **Dijkstra** → When you need the **shortest path from a single source** in a **non-negative weighted graph**.  
- **Bellman-Ford** → When the graph **has negative weights** and you need the **shortest path from a single source**.  
- **Floyd-Warshall** → When you need **shortest paths between all pairs of nodes**.

---

## 🎯 **Key Takeaways**
- **Dijkstra is faster than Bellman-Ford** but **cannot handle negative weights**.  
- **Bellman-Ford detects negative cycles**, whereas **Dijkstra doesn’t**.  
- **Floyd-Warshall is useful for dense graphs** but is **inefficient for large graphs**.  
- **DFS and BFS are traversal algorithms** and do not compute shortest paths in weighted graphs.  

---

## 📜 **License**
This project is open-source and available under the **MIT License**.

---

🔹 **Contributions are welcome!** Feel free to fork, star ⭐, or submit pull requests. 🚀

---
