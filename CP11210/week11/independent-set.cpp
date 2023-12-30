#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > adj_t;
class DFS {
    adj_t adj;
    vector<ll> dp_black, dp_white;
    const ll modulo = 1e9 + 7;

   public:
    DFS(int _n, adj_t& _adj) : adj(_adj), dp_black(_n, 0), dp_white(_n, 0) {}
    ll dfs(int u, int parent = 0) {
        dp_black[u] = 1;
        dp_white[u] = 1;
        for (auto v : adj[u]) {
            if (v == parent)
                continue;
            dfs(v, u);
            (dp_white[u] *= (dp_white[v] + dp_black[v]) % modulo) %= modulo;
            (dp_black[u] *= dp_white[v]) %= modulo;
        }
        return (dp_black[u] + dp_white[u]) % modulo;
    }
};
void solve() {
    int n;
    cin >> n;
    adj_t adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    DFS dfs(n + 1, adj);
    cout << dfs.dfs(1) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
