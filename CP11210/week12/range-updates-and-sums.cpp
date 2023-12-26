#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class range_segment_tree {
    // range (set & increase & query)
    const int _base = 1;
    const ll _val = 0;
    const ll _tag = 0;
    struct _node {
        ll val;
        ll tag;
        bool set;
    };
    int n;
    vector<_node> buf;

    ll get_val(int l, int r, int id) {
        if (buf[id].set)
            return (r - l + 1) * buf[id].tag;
        else
            return (r - l + 1) * buf[id].tag + buf[id].val;
    }
    void pull(int l, int r, int id) {
        int m = (r - l) / 2 + l;
        buf[id].val = get_val(l, m, id * 2) + get_val(m + 1, r, id * 2 + 1);
    }
    void push(int l, int r, int id) {
        buf[id].val = get_val(l, r, id);
        if (buf[id].set) {
            buf[id * 2].tag = buf[id].tag;
            buf[id * 2 + 1].tag = buf[id].tag;
            buf[id].tag = _tag;
            buf[id * 2].set = true;
            buf[id * 2 + 1].set = true;
            buf[id].set = false;
        } else {
            buf[id * 2].tag += buf[id].tag;
            buf[id * 2 + 1].tag += buf[id].tag;
            buf[id].tag = _tag;
        }
    }
    void dfs_update(int ql, int qr, ll val, bool set, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return;
        if (ql <= l && qr >= r) {
            if (!set)
                buf[id].tag += val;
            else
                buf[id].tag = val, buf[id].set = true;
            return;
        }
        push(l, r, id);
        int m = (r - l) / 2 + l;
        dfs_update(ql, qr, val, set, l, m, id * 2);
        dfs_update(ql, qr, val, set, m + 1, r, id * 2 + 1);
        pull(l, r, id);
    }
    ll dfs_query(int ql, int qr, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return _val;
        if (ql <= l && qr >= r)
            return get_val(l, r, id);
        push(l, r, id);
        int m = (r - l) / 2 + l;
        return dfs_query(ql, qr, l, m, id * 2) + dfs_query(ql, qr, m + 1, r, id * 2 + 1);
    }

   public:
    range_segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {_val, _tag, false}) {
    }
    void update(int l, int r, ll val, bool set) {
        dfs_update(l, r, val, set, _base, n - 1 + _base);
    }
    ll query(int l, int r) {
        return dfs_query(l, r, _base, n - 1 + _base);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    range_segment_tree tree(n);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        tree.update(i, i, t, true);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            tree.update(a, b, x, false);
        } else if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            tree.update(a, b, x, true);
        } else {
            int a, b;
            cin >> a >> b;
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
