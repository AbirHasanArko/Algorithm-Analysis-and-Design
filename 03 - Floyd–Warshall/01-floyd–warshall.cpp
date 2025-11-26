#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e18;

// Function to print the shortest path from s to d
void printPath(int s, int d, vector<vector<int>>& parent);

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1, -1));
    
    // Initialize adjacency and parent matrices
    for (int i = 1; i < n; i++) {
        adj[i][i] = 0;
        parent[i][i] = i;
    }

    // Read edges
    cout << "Enter edges (u v w): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        parent[u][v] = u;
    }

    // Floyd–Warshall: compute all-pairs shortest paths
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] != INF && adj[k][j] != INF && adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    cout << "\nShortest distance matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == INF) cout << "INF ";
            else cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Input source and destination for path query
    cout << "\nEnter source and destination to print path: ";

    int s, d;
    cin >> s >> d;

    // Print the shortest path and its distance
    cout << "Shortest path from " << s << " to " << d << ": ";
    printPath(s, d, parent);
    cout << "Shortest distance: " << adj[s][d] << endl;
    
    return 0;
}

void printPath(int s, int d, vector<vector<int>>& parent)
{
    if (parent[s][d] == -1) {
        cout << "No path exists";
        return;
    }
    vector<int> path;
    int v = d;
    while (v != s) {
        path.push_back(v);
        v = parent[s][v];
        if (v == -1) {
            cout << "No path exists";
            return;
        }
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << endl;
}

/*
Test Case:

input:
4 5
1 2 4
1 3 1
3 2 -2
2 4 2
3 4 3
1 4

Output:
Enter number of vertices and edges: 4 5
Enter edges (u v w):
1 2 4
1 3 1
3 2 -2
2 4 2
3 4 3

Shortest distance matrix:
0 -1 1 1 
INF 0 INF 2 
INF -2 0 0 
INF INF INF INF 

Enter source and destination to print path: 1 4
Shortest path from 1 to 4: 1 3 2 4 
Shortest distance: 1
*/
