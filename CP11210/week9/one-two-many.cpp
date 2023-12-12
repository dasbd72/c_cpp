#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> adj_t;
class disjoint_set {
    vector<int> parent;

   public:
    disjoint_set(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_root(int x) {
        int px = parent[x];
        if (x == px)
            return x;
        return parent[x] = find_root(px);
    }
    bool same(int a, int b) {
        return find_root(a) == find_root(b);
    }
    int union_basic(int a, int b) {
        return parent[find_root(a)] = find_root(b);
    }
};
void solve() {
    int n, m, u, v;
    cin >> n >> m;
    adj_t adj(n);
    disjoint_set ds(n);
    while (m--) {
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        ds.union_basic(u, v);
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        s.emplace(ds.find_root(i));
    }

    queue<int> que;
    vector<int> record(n, 0);
    bool error = false;

    for (auto u : s) {
        que.emplace(u);
        record[u] = 1;
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : adj[u]) {
            if (record[v] != 0) {
                if (record[u] == record[v])
                    error = true;
                continue;
            }
            que.emplace(v);
            record[v] = 3 - record[u];
        }
    }

    if (error)
        cout << "MANY\n";
    else {
        for (int i = 0; i < n; i++) {
            cout << record[i] << " \n"[i == n - 1];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
