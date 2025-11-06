#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (ll)1e18;

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> key(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> inMST(n + 1, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    int start = 1;
    key[start] = 0;
    pq.push({0, start});
    ll totalCost = 0, edgeCount = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        if (parent[u] != -1)
            edgeCount++;
        totalCost += key[u];

        for (auto [v, w] : adj[u])
        {
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "-" << i << " (weight: " << key[i] << ")\n";
    }

    cout << "Total minimum cost: " << totalCost << endl;
    cout << "Total edges: " << edgeCount << endl;

    return 0;
}