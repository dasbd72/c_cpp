#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int maxn = 1000001;
class range_segment_tree {
    const int _base = 1;
    const ll _val = 0;
    const ll _tag = 0;
    struct _node {
        ll val;
        ll tag;
    };
    int n;
    vector<_node> buf;

    ll get_val(int l, int r, int id) {
        return buf[id].tag ? (r - l + 1) : buf[id].val;
    }
    void pull(int l, int r, int id) {
        int m = (r - l) / 2 + l;
        buf[id].val = get_val(l, m, id * 2) + get_val(m + 1, r, id * 2 + 1);
    }
    void dfs_update(int ql, int qr, ll val, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return;
        if (ql <= l && qr >= r) {
            buf[id].tag += val;
            return;
        }
        int m = (r - l) / 2 + l;
        dfs_update(ql, qr, val, l, m, id * 2);
        dfs_update(ql, qr, val, m + 1, r, id * 2 + 1);
        pull(l, r, id);
    }

   public:
    range_segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {_val, _tag}) {
    }
    void update(int l, int r, ll val) {
        dfs_update(l, r, val, _base, n - 1 + _base);
    }
    ll query() {
        return get_val(_base, n - 1 + _base, 1);
    }
};
void solve() {
    int n, l, r, t;
    ll val;
    cin >> n;

    range_segment_tree seg(maxn * 2);
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> t;
        seg.update(l + maxn, r + maxn - 1, t);
        val = seg.query();
        cout << val << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
