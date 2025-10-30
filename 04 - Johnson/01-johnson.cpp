#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Step 1: Add a dummy node (0) connecting to all other nodes with 0 weight
    vector<ll> h(n + 1, INF);
    h[0] = 0;

    for (int i = 1; i <= n; ++i)
        edges.push_back({0, i, 0});

    // Step 2: Run Bellman-Ford from dummy node to find h(v)
    for (int i = 0; i < n; ++i) {
        for (auto &e : edges) {
            if (h[e.u] < INF && h[e.v] > h[e.u] + e.w)
                h[e.v] = h[e.u] + e.w;
        }
    }

    // Check for negative weight cycle
    for (auto &e : edges) {
        if (h[e.u] < INF && h[e.v] > h[e.u] + e.w) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    // Step 3: Reweight edges
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (auto &e : edges) {
        if (e.u == 0) continue; // skip dummy edges
        ll new_w = e.w + h[e.u] - h[e.v];
        adj[e.u].push_back({e.v, new_w});
    }

    // Step 4: Run Dijkstra from every vertex
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    for (int src = 1; src <= n; ++src) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[src][src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[src][u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[src][v] > d + w) {
                    dist[src][v] = d + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }

    // Step 5: Convert back to original distances
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (dist[u][v] < INF)
                dist[u][v] = dist[u][v] - h[u] + h[v];

    // Step 6: Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll ans = dist[a][b];
        if (ans >= INF / 2)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}
