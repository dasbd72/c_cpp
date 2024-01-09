
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, ll>>> adj_t;
const ll INF = 0x7ffffffffffffff;
class DFS {
    int n;
    adj_t adj;
    vector<ll> dp_exist;
    vector<ll> dp_del;

   public:
    DFS(adj_t& _adj) : n(_adj.size()), adj(_adj), dp_exist(n, -INF), dp_del(n, -INF) {}
    void dfs(int u, int parent = -1) {
        dp_exist[u] = 0;
        dp_del[u] = 0;
        ll sum_of_exist = 0;
        ll addition_of_del = 0;
        for (auto [v, w] : adj[u]) {
            if (v == parent)
                continue;
            dfs(v, u);
            dp_exist[u] += max(dp_exist[v], dp_del[v]);
            sum_of_exist += max(dp_exist[v], dp_del[v]);
            addition_of_del = max(addition_of_del, w - max(dp_exist[v], dp_del[v]) + dp_exist[v]);
        }
        dp_del[u] = sum_of_exist + addition_of_del;
    }
    ll ans(int u) { return max(dp_exist[u], dp_del[u]); }
};
void solve() {
    int n;
    cin >> n;
    adj_t adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    DFS G(adj);
    G.dfs(1);
    cout << G.ans(1) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
