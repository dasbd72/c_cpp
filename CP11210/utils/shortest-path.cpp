#include <bits/stdc++.h>
using namespace std;

#define INF 0x7ffffffffffffff
typedef long long ll;

// edge weight > 0
vector<ll> dijkstra(vector<vector<pair<int, ll>>> &adj, int src) {
    int n = adj.size();
    vector<ll> d(n, INF);
    vector<bool> vis(n, false);
    using QueuePair = pair<ll, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> que;
    d[src] = 0;
    que.emplace(0, src);
    while (!que.empty()) {
        int u = que.top().second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                que.emplace(d[v], v);
            }
        }
    }
    return d;
}

struct Edge {
    int u;
    int v;
    ll cost;
};
vector<ll> bellman_ford(vector<Edge> &edges, int n, int src) {
    vector<ll> d(n, INF);
    d[src] = 0;
    auto relax = [&](Edge &e) {
        if (d[e.v] > d[e.u] + e.cost) {
            d[e.v] = d[e.u] + e.cost;
            return true;
        }
        return false;
    };
    for (int t = 1; t <= n; t++) {
        bool update = false;
        for (auto &e : edges) {
            update |= relax(e);
        }
        if (t == n && update)
            return {};
    }
    return d;
}

void floyd_warshall(vector<vector<ll>> &D) {
    int n = D.size();
    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
}
