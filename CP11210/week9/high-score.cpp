#include <bits/stdc++.h>
using namespace std;

#define INF -0x7ffffffffffffff
typedef long long ll;
struct Edge {
    int u;
    int v;
    ll cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};
void dfs(vector<vector<int> >& g, vector<int>& vis, int u) {
    for (auto v : g[u]) {
        if (vis[v])
            continue;
        vis[v] = 1;
        dfs(g, vis, v);
    }
};
void solve() {
    int n, m, a, b;
    ll x;
    cin >> n >> m;
    vector<Edge> edges;
    while (m--) {
        cin >> a >> b >> x;
        a--, b--;
        edges.emplace_back(Edge(a, b, x));
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    vector<int> changed;
    auto relax = [&](Edge e) {
        if (dist[e.u] != INF && dist[e.v] < dist[e.u] + e.cost) {
            dist[e.v] = dist[e.u] + e.cost;
            changed.emplace_back(e.v);
            return true;
        }
        return false;
    };
    for (int t = 0; t < n; t++) {
        changed.clear();
        for (auto& e : edges)
            relax(e);
    }

    vector<vector<int> > rev_g(n);
    vector<int> rev_vis(n, 0);
    for (auto e : edges) {
        rev_g[e.v].emplace_back(e.u);
    }
    rev_vis[n - 1] = 1;
    dfs(rev_g, rev_vis, n - 1);

    for (auto u : changed) {
        if (rev_vis[u]) {
            cout << "-1\n";
            return;
        }
    }
    cout << dist[n - 1] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
