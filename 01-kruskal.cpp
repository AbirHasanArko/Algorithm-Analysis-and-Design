#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge
{
    int u, v;
    ll w;

    bool operator<(const Edge &other) const
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

        for (int i = 0 ; i <= n; i++) {
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

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false;
        }

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
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll totalWeight = 0;
    int totalEdges = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
            totalEdges++;
        }
    }

    if ((int)mst.size() != n-1) {
        cout << "MST not possible (Graph not connected)\n";
    }

    cout << "\nEdges in MST:\n";
    for (auto &e : mst) {
        cout << e.u << "-" << e.v << " (" << e.w <<")\n";
    }

    cout << "Total minimum cost: " << totalWeight << endl;
    cout << "Total Edges: " << totalEdges << endl;

    return 0;
}