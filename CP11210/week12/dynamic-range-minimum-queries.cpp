#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class minimum_segment_tree {
    struct node {
        ll val;
    };
    int n;
    vector<node> buf;

    void dfs_update(int pos, ll val, int l, int r, int id = 1) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            buf[id].val = val;
            return;
        }
        int m = (r - l) / 2 + l;
        dfs_update(pos, val, l, m, id * 2);
        dfs_update(pos, val, m + 1, r, id * 2 + 1);
        buf[id].val = min(buf[id * 2].val, buf[id * 2 + 1].val);
    }
    ll dfs_query(int ql, int qr, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return INT_MAX;
        if (ql <= l && qr >= r)
            return buf[id].val;
        int m = (r - l) / 2 + l;
        return min(dfs_query(ql, qr, l, m, id * 2), dfs_query(ql, qr, m + 1, r, id * 2 + 1));
    }

   public:
    minimum_segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {INT_MAX}) {
    }
    void update(int pos, ll val) {
        dfs_update(pos, val, 0, n - 1);
    }
    ll query(int l, int r) {
        return dfs_query(l, r, 0, n - 1);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    minimum_segment_tree tree(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        tree.update(i, x);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--;
            tree.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << tree.query(a, b) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
