#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Edge
{
    int u, v;
    ll w;

    // For sorting edges by weight (ascending)
    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y) return false;

        if (rank[x] < rank[y]) swap(x, y);

        parent[y] = x;

        if (rank[x] == rank[y]) rank[x]++;

        return true;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<Edge> mst;
    ll totalWeight = 0;

    // Kruskal's algorithm: pick edges in increasing weight order
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
        }
    }

    // Count number of trees (connected components) after MST
    unordered_set<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(dsu.find(i));
    }
    int numberOfTrees = roots.size();

    // Output MST/forest edges
    cout << "\nEdges in forest/MST:\n";
    for (auto &e : mst) {
        cout << e.u << "-" << e.v << " (Weight: " << e.w << ")\n";
    }

    // Output total cost, edges used, and number of trees
    cout << "\nTotal minimum cost (sum of all MST components): " << totalWeight << endl;

    cout << "Total edges used: " << mst.size() << endl;;

    if (numberOfTrees == 1)
        cout << "Graph is connected -> Only 1 MST.\n";
    else
        cout << "Graph is NOT fully connected -> Number of trees in forest = " << numberOfTrees << "\n";

    return 0;
}

/*
Test Case 1:

Input:
5 7
1 2 2
1 3 3
1 4 1
2 3 4
2 5 3
3 5 2
4 5 5

Output:
Enter number of vertices and edges: 5 7
1 2 2
1 3 3
1 4 1
2 3 4
2 5 3
3 5 2
4 5 5

Edges in forest/MST:
1-4 (Weight: 1)
1-2 (Weight: 2)
3-5 (Weight: 2)
1-3 (Weight: 3)

Total minimum cost (sum of all MST components): 8
Total edges used: 4
Graph is connected -> Only 1 MST
*/

/*
Test Case 2:

Input:
7 5
1 2 2
3 4 3
4 5 1
6 7 4
2 1 2

Output:
Enter number of vertices and edges:
 7 5
1 2 2
3 4 3
4 5 1
6 7 4
2 1 2

Edges in forest/MST:
4-5 (Weight: 1)
1-2 (Weight: 2)
3-4 (Weight: 3)
6-7 (Weight: 4)

Total minimum cost (sum of all MST components): 10
Total edges used: 4
Graph is NOT fully connected -> Number of trees in forest = 3 
*/
