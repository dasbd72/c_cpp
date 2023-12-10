#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class disjoint_set {
    vector<int> parent;
    vector<int> rank;

   public:
    disjoint_set(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
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
    int union_by_rank(int a, int b) {
        int ra = find_root(a), rb = find_root(b);
        if (rank[ra] > rank[rb])
            swap(ra, rb);
        if (rank[ra] == rank[rb])
            ++rank[rb];
        return parent[ra] = rb;
    }
};
void solve() {
    int n, m, x, y, z;
    cin >> n >> m;
    disjoint_set ds(n);
    while (m--) {
        cin >> x >> y >> z;
        x--, y--;
        ds.union_basic(x, y);
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.emplace(ds.find_root(i));
    }
    cout << st.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
