#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class segment_tree {
    const int _base = 1;
    struct _node {
        ll val;
        ll prefix, all, suffix;
    };
    int n;
    vector<_node> buf;

    void pull(int id) {
        buf[id].val = buf[id * 2].val + buf[id * 2 + 1].val;
        buf[id].prefix = max(buf[id * 2].prefix, buf[id * 2].val + buf[id * 2 + 1].prefix);
        buf[id].suffix = max(buf[id * 2 + 1].suffix, buf[id * 2 + 1].val + buf[id * 2].suffix);
        buf[id].all = max(max(buf[id * 2].all, buf[id * 2 + 1].all), buf[id * 2].suffix + buf[id * 2 + 1].prefix);
    }
    void dfs_update(int pos, ll val, int l, int r, int id = 1) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            buf[id].val = val;
            buf[id].prefix = max((ll)0, val);
            buf[id].suffix = max((ll)0, val);
            buf[id].all = max((ll)0, val);
            return;
        }
        int m = (r - l) / 2 + l;
        dfs_update(pos, val, l, m, id * 2);
        dfs_update(pos, val, m + 1, r, id * 2 + 1);
        pull(id);
    }

   public:
    segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {0, 0, 0, 0}) {
    }
    void update(int pos, ll val) {
        dfs_update(pos, val, _base, n - 1 + _base);
    }
    ll query() {
        return buf[1].all;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    segment_tree tree(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree.update(i, x);
    }
    while (m--) {
        int k, x;
        cin >> k >> x;
        tree.update(k, x);
        cout << tree.query() << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
