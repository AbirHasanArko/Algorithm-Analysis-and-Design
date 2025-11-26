# Floyd–Warshall Algorithm (All-Pairs Shortest Paths)

This project demonstrates the **Floyd–Warshall algorithm**, a classic dynamic programming algorithm used to compute **shortest paths between all pairs of vertices** in a weighted graph. It also supports **path reconstruction** for any source-destination pair.

---

## Problem Overview

Given a weighted graph (directed or undirected) with possible negative edge weights (but no negative cycles), the goals are:

- Compute the **shortest distance** between every pair of vertices.
- Reconstruct the **shortest path** from a specified source to destination vertex.

This problem is useful in:

- Network routing  
- Traffic optimization  
- Transitive closure and reachability analysis  
- Competitive programming challenges  

---

## Algorithm Overview

**Floyd–Warshall algorithm** uses **dynamic programming**:

1. Initialize a distance matrix `dist[i][j]` with direct edge weights (`INF` if no edge) and a parent matrix for path reconstruction.
2. Iteratively update the distance matrix for each intermediate vertex `k`:
   - `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
   - Update `parent[i][j]` to reconstruct the path.
3. After all iterations, `dist[i][j]` contains the shortest distance from `i` to `j`, and the parent matrix allows path reconstruction.

**Paradigm:** Dynamic Programming  
**Key Property:** Can handle negative weights, but **cannot handle negative cycles**.

---

## Input & Output
`n m`  
`u1 v1 w1`  
`u2 v2 w2`  
`...`  
`um vm wm`  
`s d`  

Where:

- `n` : number of vertices  
- `m` : number of edges  
- `ui, vi` : endpoints of each edge  
- `wi` : weight of the edge (can be negative, no negative cycles)  
- `s` : source vertex for path query  
- `d` : destination vertex for path query  

**Output:**

- Shortest distance matrix for all pairs of vertices  
- Shortest path and distance between `s` and `d`

---

## Time and Space Complexity

| Aspect | Complexity |
|--------|------------|
| Time   | `O(V^3)` – three nested loops over all vertices |
| Space  | `O(V^2)` – adjacency (distance) and parent matrices |

Where `V` is the number of vertices.

> Suitable for **small to medium graphs**. For very large graphs, consider Dijkstra’s algorithm for single-source shortest paths.

---

## Example
Enter number of vertices and edges: `4 5`  
Enter edges (u v w):  
`1 2 4`  
`1 3 1`  
`3 2 -2`  
`2 4 2`  
`3 4 3`  

Shortest distance matrix:  
0 -1 1 1   
INF 0 INF 2   
INF -2 0 0   
INF INF INF INF   

Enter source and destination to print path: `1 4`  
Shortest path from 1 to 4: 1 3 2 4   
Shortest distance: 1  

---

## Notes

- Works for **directed and undirected graphs**.  
- Can handle **negative edge weights**, but **negative cycles are not supported**.  
- Uses a **parent matrix** to reconstruct shortest paths efficiently.  
- Ideal for solving **all-pairs shortest path** problems in graphs with moderate vertex counts.
