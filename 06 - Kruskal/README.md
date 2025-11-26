# Kruskal's Algorithm (Minimum Spanning Tree / Forest)

This project demonstrates **Kruskal's algorithm**, a classic greedy algorithm to compute the **Minimum Spanning Tree (MST)** of a weighted, undirected graph. When the graph is disconnected, it computes a **minimum spanning forest**, consisting of the MSTs of each connected component.

---

## Problem Overview

Given a weighted, undirected graph:

- Find a subset of edges that connects all vertices in a connected component (spanning tree)  
- Minimize the **total weight** of the selected edges  
- Ensure no cycles are formed  

Kruskal’s algorithm sorts edges by weight and adds them to the MST if they do not create a cycle.

**This problem is useful in:**

- Network design (minimum cost connections)  
- Circuit design and electrical networks  
- Clustering problems in machine learning  
- Optimization problems in graphs and competitive programming

---

## Algorithm Overview

**Kruskal's algorithm** uses a **greedy approach** and **Disjoint Set Union (DSU / Union-Find)**:

1. Sort all edges in **ascending order** of weight.  
2. Initialize a DSU to track connected components.  
3. Iterate over edges:
   - If adding an edge does **not form a cycle** (its endpoints are in different sets), include it in the MST and unite the sets.  
4. Repeat until all vertices in each component are connected.  
5. If the graph is disconnected, the algorithm produces a **minimum spanning forest**.

**Paradigm:** Greedy  
**Key Property:** Efficient for sparse graphs and supports multiple connected components.

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

- List of MST (or forest) edges with weights  
- Total minimum cost (sum of all MST components)  
- Total number of edges used  
- Number of trees in the forest (1 if graph is connected)  

---

## Time and Space Complexity

| Aspect | Complexity |
|--------|------------|
| Time   | `O(E log E)` for sorting edges + `O(E α(V))` for union-find operations (α = inverse Ackermann function) |
| Space  | `O(V + E)` for edges + DSU parent/rank arrays |

Where `V` is the number of vertices and `E` is the number of edges.

---

## Example

**Test Case 1 (Connected Graph):**
Enter number of vertices and edges: `5 7`  
Enter edges (u v w):  
`1 2 2`  
`1 3 3`  
`1 4 1`  
`2 3 4`  
`2 5 3`  
`3 5 2`  
`4 5 5`  

Edges in forest/MST:  
1-4 (Weight: 1)  
1-2 (Weight: 2)  
3-5 (Weight: 2)  
1-3 (Weight: 3)  

Total minimum cost (sum of all MST components): 8  
Total edges used: 4  
Graph is connected -> Only 1 MST  

**Test Case 2 (Disconnected Graph):**
Enter number of vertices and edges: `7 5`  
Enter edges (u v w):   
`1 2 2`  
`3 4 3`  
`4 5 1`  
`6 7 4`  
`2 1 2`  

Edges in forest/MST:  
4-5 (Weight: 1)  
1-2 (Weight: 2)  
3-4 (Weight: 3)  
6-7 (Weight: 4)  

Total minimum cost (sum of all MST components): 10  
Total edges used: 4  
Graph is NOT fully connected -> Number of trees in forest = 3   

---

## Notes

- Works for **connected and disconnected graphs**.  
- Uses **Disjoint Set Union (DSU / Union-Find)** to efficiently detect cycles.  
- Produces a **minimum spanning forest** when the graph is disconnected.  
- Useful for network design, clustering, and optimization problems in graphs.
