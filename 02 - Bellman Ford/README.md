# Bellman-Ford Algorithm (Shortest Path with Negative Weights)

This project demonstrates **Bellman-Ford algorithm**, a fundamental graph algorithm used to compute **shortest paths from a source vertex to all other vertices** in a weighted graph. Unlike Dijkstra’s algorithm, Bellman-Ford can handle **negative edge weights** and can detect **negative weight cycles**, including reconstructing the cycle path.

---

## Problem Overview

Given a weighted directed graph (or undirected by modeling edges in both directions), the goals are:

- Compute the minimum distance from a **source vertex** to all other vertices.
- Reconstruct the shortest path to a specified target vertex (if reachable).
- Detect **negative weight cycles** and reconstruct the cycle path.

This problem appears in:

- Network routing with potential negative costs  
- Currency arbitrage detection  
- Competitive programming graph problems  

---

## Algorithm Overview

**Bellman-Ford algorithm** is based on **dynamic programming / edge relaxation**:

1. Initialize distances from source to all vertices as infinity, except the source itself which is 0.
2. Relax **all edges** repeatedly `(V-1)` times, updating the shortest known distances.
3. After `(V-1)` relaxations, check all edges one more time:
   - If any edge can still be relaxed, a **negative weight cycle** exists.
4. Optionally, reconstruct shortest paths using a **parent (predecessor) array**.
5. If a negative cycle is detected, the algorithm can **reconstruct the cycle path** by following parent links inside the cycle.

**Paradigm:** Dynamic Programming / Greedy relaxation  
**Key Property:** Can handle negative weights and detect negative cycles  

---

## Input & Output
`n`  
`m`  
`u1 v1 w1`  
`u2 v2 w2`  
`...`  
`um vm wm`  
`src`  
`t`  


Where:

- `n` : number of vertices  
- `m` : number of edges  
- `ui, vi` : endpoints of each edge  
- `wi` : weight of the edge (can be negative)  
- `src` : source vertex  
- `t` : target vertex to display the shortest path  

**Output:**

- Shortest distance from source to each vertex (or `INF` if unreachable)  
- Shortest path from source to target vertex  
- Notification of a negative weight cycle, if detected  
- **Reconstructed negative cycle path**, if a cycle exists  

---

## Time and Space Complexity

| Aspect | Complexity |
|--------|------------|
| Time   | `O(V * E)` – relax all edges `(V-1)` times |
| Space  | `O(V + E)` – edge list + `O(V)` for distance and parent arrays |

Where `V` is the number of vertices and `E` is the number of edges.  

> Bellman-Ford is slower than Dijkstra for graphs without negative edges, but it handles **negative weights** and **cycle detection**.

---

## Applications

- Shortest path calculations with possible negative weights  
- Detecting negative cycles in graphs (useful in finance and arbitrage)  
- Competitive programming problems involving weighted graphs  
- Reconstructing negative cycles to analyze feedback loops or system inconsistencies  

---

## Example

**Example 1**  
Enter number of vertices: `6`  
Enter number of edges: `8`  

Enter each edge as: u v w
(Example: for edge u -> v with weight w, enter: 1 2 5)  
`1 2 4`  
`1 3 2`  
`2 3 -1`  
`2 4 2`  
`3 5 3`  
`5 4 -2`  
`4 6 1`  
`5 6 5`  

Enter the source vertex: `1`

No negative weight cycle found.

Shortest distances from source vertex 1:
Vertex 1 : 0
Vertex 2 : 4
Vertex 3 : 2
Vertex 4 : 3
Vertex 5 : 5
Vertex 6 : 4

Enter the target vertex to show shortest path: `6`

Shortest Path: 1 3 5 4 6 
Total Cost: 4

**Example 2**  
Enter number of vertices: `4`  
Enter number of edges: `5`  

Enter each edge as: u v w
(Example: for edge u -> v with weight w, enter: 1 2 5)  
`1 2 1`  
`2 3 -1`  
`3 4 -1`  
`4 2 -1`  
`1 4 5`  

Enter the source vertex: `1`  

Negative weight cycle detected!  
Cycle involves vertices: 2 3 4 2   

---

## Notes

- Can handle **negative edge weights**, unlike Dijkstra.  
- Detects **negative cycles** and reconstructs the cycle path.  
- Uses **parent arrays** for both path and cycle reconstruction.  
- Works for both **directed and undirected graphs** (model undirected edges as two directed edges).  
