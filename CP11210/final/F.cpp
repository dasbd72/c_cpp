#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, ll>>> adj_t;
const ll INF = 0x7ffffffffffffff;
ll dijkstra(adj_t &adj, int src, int dst) {
    int n = adj.size();
    vector<ll> d(n, INF);
    vector<bool> vis(n, false);
    using QueuePair = pair<ll, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> que;
    d[src] = 0;
    que.emplace(0, src);
    while (!que.empty()) {
        int u = que.top().second;
        que.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto [v, w] : adj[u]) {
            if (d[v] > max(d[u], w)) {
                d[v] = max(d[u], w);
                que.emplace(d[v], v);
            }
        }
    }
    return d[dst];
}
void solve() {
    int n, q;
    cin >> n;
    adj_t adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        // query
        cout << dijkstra(adj, x, y) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}