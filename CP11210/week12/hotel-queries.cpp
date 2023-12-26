#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template <class Ty>
class segment_tree {
    struct node {
        Ty val;
        int pos;
    };
    int n;
    vector<node> buf;

    Ty op(Ty a, Ty b) {
        return max(a, b);
    }
    void dfs_update(int pos, Ty val, int l, int r, int id = 1) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            buf[id].val += val;
            buf[id].pos = pos;
            return;
        }
        int m = (r - l) / 2 + l;
        dfs_update(pos, val, l, m, id * 2);
        dfs_update(pos, val, m + 1, r, id * 2 + 1);
        buf[id].val = op(buf[id * 2].val, buf[id * 2 + 1].val);
    }
    pair<Ty, int> dfs_query(Ty val, int l, int r, int id = 1) {
        if (buf[id].val < val)
            return {0, 0};
        if (l == r)
            return {buf[id].val, buf[id].pos};
        int m = (r - l) / 2 + l;
        auto res_l = dfs_query(val, l, m, id * 2);
        if (res_l.second != 0)
            return res_l;
        return dfs_query(val, m + 1, r, id * 2 + 1);
    }

   public:
    segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {0, 0}) {
    }
    void update(int pos, Ty val) {
        dfs_update(pos, val, 1, n);
    }
    pair<Ty, int> query(Ty val) {
        return dfs_query(val, 1, n);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    segment_tree<ll> tree(n);
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        tree.update(i, h);
    }
    for (int i = 1; i <= m; i++) {
        int r;
        cin >> r;
        auto res = tree.query(r);
        if (res.second > 0) {
            tree.update(res.second, -r);
        }
        cout << res.second << " \n"[i == m];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
