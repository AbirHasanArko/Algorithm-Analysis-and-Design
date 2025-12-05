#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60); // A large value representing infinity

/*
  * Program: Dijkstra's Algorithm (Undirected Graph)
  ------------------------------------------------
  This program finds the shortest distances from a given source vertex
  to all other vertices in a weighted undirected graph using Dijkstra's algorithm.
  
 * INPUT FORMAT:
  ---------------
  n m
  u1 v1 w1
  u2 v2 w2
  ...
  um vm wm
  src
  t
  
 * where:
  - n  : number of vertices (0 to n-1)
  - m  : number of edges
  - ui, vi : endpoints of each edge
  - wi : weight (cost) of the edge
  - src : source vertex
  - t   : target vertex to show the path
 */

int main()
{
    cout << "Hello!\n\n";
    
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // adjacency list

    cout << "Enter each edge as (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        // since graph is undirected
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<ll> dist(n + 1, INF);    // stores shortest distance
    vector<int> parent(n + 1, -1);  // stores parent for path reconstruction
    dist[src] = 0;

    // priority_queue for selecting the next vertex with minimum distance
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});

    // Dijkstra's algorithm loop
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // if current distance is outdated, skip
        if (d != dist[u]) continue;

        // explore all adjacent vertices
        for (auto &e : adj[u]) {
            int v = e.first;
            ll w = e.second;

            // relax edge if a shorter path is found
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // display shortest distances from source
    cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << " : INF\n";
        } else {
            cout << "Vertex " << i << " : " << dist[i] << "\n";
        }
    }

    int t;
    cout << "\nEnter the target vertex to show shortest path: ";
    cin >> t;

    // show shortest path from source to target
    if (dist[t] == INF) {
        cout << "No Path\n";
    } else {
        vector<int> path;
        for (int v = t; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "\nShortest Path: ";
        for (int x : path) cout << x << " ";
        cout << "\nTotal Cost: " << dist[t] << "\n";
    }

    return 0;
}

/*
Test case:
Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1
5

Output:
Enter number of vertices and edges: 5 6
Enter each edge as (u v w):
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
Enter the source vertex: 1

Shortest distances from source vertex 1:
Vertex 1 : 0
Vertex 2 : 2
Vertex 3 : 3
Vertex 4 : 7
Vertex 5 : 6

Enter the target vertex to show shortest path: 5

Shortest Path: 1 2 3 5 
Total Cost: 6
*/
