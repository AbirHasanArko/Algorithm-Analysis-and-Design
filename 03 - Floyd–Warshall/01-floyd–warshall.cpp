#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18; // A large value representing infinity

int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    ll adj[v][v];

    // Initialize adjacency matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }

    // Read edges
    cout << "Enter edges (u v w): " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // Print shortest paths
    cout << "Shortest paths:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == INF)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
