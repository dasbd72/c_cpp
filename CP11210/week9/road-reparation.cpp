#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<pair<int, ll>>> adj_t;
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
    int n, m, a, b;
    ll c;
    cin >> n >> m;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    while (m--) {
        cin >> a >> b >> c;
        a--, b--;
        pq.emplace(c, a, b);
    }

    ll cost = 0;
    disjoint_set ds(n);
    while (!pq.empty()) {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (ds.same(u, v))
            continue;
        ds.union_basic(u, v);
        cost += w;
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        s.emplace(ds.find_root(i));
    }
    if (s.size() > 1)
        cout << "IMPOSSIBLE\n";
    else
        cout << cost << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
