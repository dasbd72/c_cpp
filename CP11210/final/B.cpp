#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, ll>>> adj_t;
const ll INF = 0x7ffffffffffffff;
ll dijkstra(adj_t &adj, int src, ll off) {
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
            if (d[v] > d[u] + max(w - off, (ll)1)) {
                d[v] = d[u] + max(w - off, (ll)1);
                que.emplace(d[v], v);
            }
        }
    }
    return d[n - 1];
}
void solve() {
    int n, m;
    ll k = 1e18;
    cin >> n >> m >> k;
    adj_t adj(n);
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    // input done
    auto check = [&](int off) { return dijkstra(adj, 0, off) <= k; };
    ll l = 0, r = 1e12;
    while (l < r) {
        int m = (r - l) / 2 + l;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}