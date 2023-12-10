#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class tree {
    int n;
    vector<vector<int> > edge;

    int ans;
    vector<int> size;

    void dfs(int u, int parent = -1) {
        size[u] = 1;
        int max_son_size = 0;
        for (auto v : edge[u]) {
            if (v == parent)
                continue;
            dfs(v, u);
            size[u] += size[v];
            max_son_size = max(max_son_size, size[v]);
        }
        max_son_size = max(max_son_size, n - size[u]);
        if (max_son_size <= n / 2)
            ans = u;
    }

   public:
    tree(int n) : n(n), edge(n), size(n, 0) {}
    void push(int u, int v) {
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    int centroid() {
        dfs(0);
        return ans;
    }
};
void solve() {
    int n, u, v;
    cin >> n;
    tree t(n);
    while (--n) {
        cin >> u >> v;
        t.push(u - 1, v - 1);
    }
    cout << t.centroid() + 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
