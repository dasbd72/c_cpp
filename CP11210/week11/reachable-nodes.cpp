#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > adj_t;
class DFS {
   public:
    int ts;
    vector<bitset<50001> > dp;
    DFS(int n) : dp(n + 1, 0) {
    }
    void dfs(const adj_t& adj, int u) {
        if (dp[u].any())
            return;
        dp[u][u] = 1;
        for (auto v : adj[u]) {
            dfs(adj, v);
            dp[u] |= dp[v];
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    adj_t adj(n + 1);
    vector<int> in_deg(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        in_deg[v]++;
    }
    DFS dfs(n);
    for (int i = 1; i <= n; i++) {
        dfs.dfs(adj, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << dfs.dp[i].count() << " \n"[i == n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
