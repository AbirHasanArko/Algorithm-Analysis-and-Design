# Dijkstra's Algorithm (Shortest Path in Weighted Graphs)

This project demonstrates **Dijkstra's algorithm**, a classic graph algorithm used to find the **shortest paths from a source vertex to all other vertices** in a weighted graph. It also allows reconstructing the path to any target vertex.

---

## Problem Overview

Given a weighted graph (directed or undirected) with non-negative edge weights, the goal is to:

- Compute the minimum distance from a **source vertex** to every other vertex.
- Optionally reconstruct the **shortest path** to a given target vertex.

This problem is fundamental in graph theory and appears in:

- Network routing (e.g., finding shortest paths in road maps)
- Resource optimization
- Real-time navigation systems
- Competitive programming challenges

---

## Algorithm Overview

**Dijkstra's algorithm** is a **greedy algorithm** based on the following idea:

1. Maintain a distance array `dist[]` where `dist[v]` is the shortest known distance from the source to vertex `v`.
2. Start from the source vertex and explore adjacent vertices.
3. Always select the vertex with the **minimum tentative distance** (using a priority queue).
4. **Relax edges**: update distances to neighbors if a shorter path is found.
5. Repeat until all vertices have been processed.

This ensures that once a vertex is processed, its shortest distance from the source is finalized.

**Paradigm:** Greedy

**Key Property:** Works only with **non-negative edge weights**.

---

## Input & Output
`n m`  
`u1 v1 w1`  
`u2 v2 w2`  
`...`  
`um vm wm`  
`src`  
`t`  


Where:

- `n` : number of vertices
- `m` : number of edges
- `ui, vi` : endpoints of an edge
- `wi` : weight of the edge (must be non-negative)
- `src` : source vertex
- `t` : target vertex to display the path

**Output:**

- Shortest distance from source to each vertex.
- Shortest path from source to target vertex (if reachable).

---

## Time and Space Complexity

| Aspect | Complexity |
|--------|------------|
| Time   | `O((V + E) log V)` using a **priority queue** (min-heap) |
| Space  | `O(V + E)` for adjacency list + `O(V)` for distance and parent arrays |

Where `V` is the number of vertices and `E` is the number of edges.

- Efficient for **sparse graphs**.
- For dense graphs, **Fibonacci heap** can reduce theoretical complexity, though standard priority queues are usually faster in practice.

---

## Applications

- Shortest path in road networks
- GPS navigation systems
- Network packet routing
- Game AI pathfinding
- Solving classic competitive programming graph problems

---

## Notes

- Only works for **non-negative edge weights**. Use **Bellman-Ford** if negative weights exist.
- Can handle **undirected or directed graphs**.
- Can reconstruct paths using a **parent array** or predecessor list.

---

This project demonstrates a practical implementation of Dijkstra's algorithm and serves as a reference for understanding shortest path problems in weighted graphs.

