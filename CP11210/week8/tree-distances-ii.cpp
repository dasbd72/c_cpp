#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void dfs(const vector<vector<int> >& tree, vector<int>& sz, vector<ll>& dist, int depth, int u, int parent = -1) {
    dist[1] += depth;
    for (auto v : tree[u]) {
        if (v == parent)
            continue;
        dfs(tree, sz, dist, depth + 1, v, u);
        sz[u] += sz[v];
    }
    sz[u]++;
}
void dfs2(int n, const vector<vector<int> >& tree, const vector<int>& sz, vector<ll>& dist, int u, int parent = -1) {
    for (auto v : tree[u]) {
        if (v == parent)
            continue;
        dist[v] = dist[u] + n - 2 * sz[v];
        dfs2(n, tree, sz, dist, v, u);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int> > tree;
    tree.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    vector<int> sz(n + 1, 0);
    vector<ll> dist(n + 1, 0);
    dfs(tree, sz, dist, 0, 1);
    dfs2(n, tree, sz, dist, 1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " \n"[i == n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
