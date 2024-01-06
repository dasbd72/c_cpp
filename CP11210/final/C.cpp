#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class range_segment_tree {
    const int _base = 1;
    const pair<ll, int> _val = {0, 0};
    const ll _tag = 0;
    struct _node {
        pair<ll, int> val;
        ll tag;
    };
    int n;
    vector<_node> buf;

    pair<ll, int> get_val(int l, int r, int id) {
        return {buf[id].tag + buf[id].val.first, buf[id].val.second};
    }
    void pull(int l, int r, int id) {
        int m = (r - l) / 2 + l;
        auto lval = get_val(l, m, id * 2);
        auto rval = get_val(m + 1, r, id * 2 + 1);
        if (lval.first != rval.first)
            buf[id].val = max(lval, rval);
        else
            buf[id].val = {lval.first, lval.second + rval.second};
    }
    void push(int l, int r, int id) {
        buf[id].val = get_val(l, r, id);
        buf[id * 2].tag += buf[id].tag;
        buf[id * 2 + 1].tag += buf[id].tag;
        buf[id].tag = _tag;
    }
    void dfs_update(int ql, int qr, ll val, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return;
        if (ql <= l && qr >= r) {
            buf[id].tag += val;
            if (ql == qr)
                buf[id].val.second = 1;
            return;
        }
        push(l, r, id);
        int m = (r - l) / 2 + l;
        dfs_update(ql, qr, val, l, m, id * 2);
        dfs_update(ql, qr, val, m + 1, r, id * 2 + 1);
        pull(l, r, id);
    }
    pair<ll, int> dfs_query(int ql, int qr, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return _val;
        if (ql <= l && qr >= r)
            return get_val(l, r, id);
        push(l, r, id);
        int m = (r - l) / 2 + l;
        auto lval = dfs_query(ql, qr, l, m, id * 2);
        auto rval = dfs_query(ql, qr, m + 1, r, id * 2 + 1);
        if (lval.first != rval.first)
            return max(lval, rval);
        else
            return {lval.first, lval.second + rval.second};
    }

   public:
    range_segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {_val, _tag}) {
    }
    void update(int l, int r, ll val) {
        dfs_update(l, r, val, _base, n - 1 + _base);
    }
    pair<ll, int> query(int l, int r) {
        return dfs_query(l, r, _base, n - 1 + _base);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    range_segment_tree tree(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree.update(i, i, x);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.update(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            auto ret = tree.query(l, r);
            cout << ret.first << " " << ret.second << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}