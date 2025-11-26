// https://cses.fi/problemset/task/1196/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0; // start from Syrjälä, coupon not used yet

    // Priority queue: {distance, node, coupon_used}
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (d != dist[u][used]) continue;

        for (auto &e : adj[u]) {
            int v = e.to;
            ll w = e.w;

            // 1. Move without using coupon
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }

            // 2. Use coupon if not used yet
            if (used == 0) {
                ll w_half = w / 2;
                if (dist[v][1] > dist[u][0] + w_half) {
                    dist[v][1] = dist[u][0] + w_half;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << "\n"; // cheapest route to Metsälä using coupon once
    return 0;
}
