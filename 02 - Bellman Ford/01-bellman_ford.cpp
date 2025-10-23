#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

int main() {
    int n, m;

    // Step 1: Take graph input
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    struct Edge {
        int u, v;
        ll w;
    };

    vector<Edge> edges;

    cout << "\nEnter each edge as: u v w\n";
    cout << "(Example: for edge u→v with weight w, enter: 0 1 5)\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Step 2: Choose source vertex
    int src;
    cout << "\nEnter the source vertex: ";
    cin >> src;

    // Step 3: Initialize distance and parent arrays
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);
    dist[src] = 0;

    // Step 4: Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;

        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                updated = true;
            }
        }

        // Optimization: stop early if no update in a pass
        if (!updated) break;
    }

    // Step 5: Check for negative weight cycles
    int cycleStart = -1;

    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            cycleStart = e.v;
            parent[e.v] = e.u;
            break;
        }
    }

    // Step 6: If no negative cycle found → print shortest distances
    if (cycleStart == -1) {
        cout << "\nNo negative weight cycle found.\n";

        cout << "\nShortest distances from source vertex " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INF)
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }

        // Step 7: Optionally show shortest path to a target vertex
        int t;
        cout << "\nEnter the target vertex to show shortest path: ";
        cin >> t;

        if (dist[t] == INF) {
            cout << "\nNo path exists from " << src << " to " << t << ".\n";
        } else {
            vector<int> path;
            for (int v = t; v != -1; v = parent[v])
                path.push_back(v);
            reverse(path.begin(), path.end());

            cout << "\nShortest Path: ";
            for (int x : path) cout << x << " ";
            cout << "\nTotal Cost: " << dist[t] << "\n";
        }
    }

    //  Step 8: If a negative cycle is found → reconstruct and print it
    else {
        // Walk back n times to ensure we are inside the cycle
        for (int i = 0; i < n; i++)
            cycleStart = parent[cycleStart];

        vector<int> cycle;
        int v = cycleStart;

        // Reconstruct the cycle
        do {
            cycle.push_back(v);
            v = parent[v];
        } while (v != cycleStart && v != -1);

        cycle.push_back(cycleStart);
        reverse(cycle.begin(), cycle.end());

        cout << "\nNegative weight cycle detected!\n";
        cout << "Cycle involves vertices: ";
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
