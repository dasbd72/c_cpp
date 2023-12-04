#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void dfs(const vector<vector<int> >& tree, vector<int>& dist, int u, int parent = -1) {
    for (auto v : tree[u]) {
        if (v == parent)
            continue;
        dist[v] = dist[u] + 1;
        dfs(tree, dist, v, u);
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

    vector<int> dist(n + 1, 0), dist_a(n + 1, 0), dist_b(n + 1, 0);
    dfs(tree, dist, 1);
    int pa = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    dfs(tree, dist_a, pa);
    int pb = max_element(dist_a.begin() + 1, dist_a.end()) - dist_a.begin();
    dfs(tree, dist_b, pb);

    for (int i = 1; i <= n; i++) {
        cout << max(dist_a[i], dist_b[i]) << " \n"[i == n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
