# Prim's Algorithm (Minimum Spanning Tree)

This project demonstrates **Prim's algorithm**, a classic greedy algorithm used to find a **Minimum Spanning Tree (MST)** of a weighted, connected undirected graph. The MST connects all vertices with the **minimum total edge weight** and no cycles.

---

## Problem Overview

Given a weighted, undirected graph:

- Find a subset of edges that connects all vertices (spanning tree)  
- Minimize the **total weight** of the selected edges  
- Ensure no cycles are formed  

Prim's algorithm builds the MST **incrementally**, starting from an arbitrary vertex and repeatedly adding the **cheapest edge** that connects a new vertex to the growing tree.

**This problem is useful in:**

- Network design (minimum cost connections)  
- Circuit design and electrical networks  
- Traffic routing and infrastructure planning  
- Optimization problems in graphs and competitive programming

---

## Algorithm Overview

**Prim's algorithm** is based on a **greedy approach**:

1. Initialize all vertex keys to infinity, except the starting vertex set to 0.  
2. Maintain a priority queue to pick the vertex with the **minimum key** not yet included in the MST.  
3. For the selected vertex, mark it as included in the MST and update the keys of adjacent vertices if a cheaper connection exists.  
4. Repeat until all vertices are included.  

**Paradigm:** Greedy  
**Key Property:** Works efficiently for dense and sparse graphs with non-negative edge weights.

---

## Input & Output

**Input format:**

`n m`  
`u1 v1 w1`  
`u2 v2 w2`  
`...`  
`um vm wm`  

Where:

- `n` : number of vertices  
- `m` : number of edges  
- `ui, vi` : endpoints of each edge  
- `wi` : weight of the edge  

**Output:**

- List of MST edges and their weights  
- Total cost of the MST  
- Number of edges in the MST

---

## Time and Space Complexity

| Aspect | Complexity |
|--------|------------|
| Time   | `O(E log V)` using a priority queue (min-heap) |
| Space  | `O(V + E)` for adjacency list + `O(V)` for keys, parents, and MST tracking |

Where `V` is the number of vertices and `E` is the number of edges.

---

## Example
Enter number of vertices and edges: `5 6`  
Enter edges (u v w):  
`1 2 2`   
`1 3 3`  
`2 3 1`  
`2 4 4`  
`3 4 5`  
`4 5 7`  

MST Edges:  
1-2 (weight: 2)  
2-3 (weight: 1)  
2-4 (weight: 4)  
4-5 (weight: 7)  
Total minimum cost: 14  
Total edges: 4  

---

## Notes

- Works for **connected, undirected graphs** with **non-negative edge weights**.  
- Uses a **priority queue** to efficiently select the next vertex.  
- Can start from any arbitrary vertex; MST total cost remains the same.  
- Ideal for network design, circuit design, and optimization problems.
