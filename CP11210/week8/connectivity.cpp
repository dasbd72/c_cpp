#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class disjoint_set {
    std::vector<int> parent;
    std::vector<int> rank;

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
    int n, k, l, a, b;
    cin >> n >> k >> l;

    disjoint_set ds1(n + 1), ds2(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        ds1.union_basic(a, b);
    }
    for (int i = 0; i < l; i++) {
        cin >> a >> b;
        ds2.union_basic(a, b);
    }

    map<pair<int, int>, int> ans;
    for (int i = 1; i <= n; i++) {
        ans[make_pair(ds1.find_root(i), ds2.find_root(i))]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[make_pair(ds1.find_root(i), ds2.find_root(i))] << " \n"[i == n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
