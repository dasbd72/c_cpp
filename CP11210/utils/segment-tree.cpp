#include <bits/stdc++.h>
using namespace std;

template <class Ty>
class segment_tree {
    struct node {
        Ty val;
    };
    int n;
    vector<node> buf;

    Ty op(Ty a, Ty b) {
        // TODO: modify
        return a + b;
    }
    void dfs_update(int pos, Ty val, int l, int r, int id = 1) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            buf[id].val = val;
            return;
        }
        int m = (r - l) / 2 + l;
        dfs_update(pos, val, l, m, id * 2);
        dfs_update(pos, val, m + 1, r, id * 2 + 1);
        buf[id].val = op(buf[id * 2].val, buf[id * 2 + 1].val);
    }
    Ty dfs_query(int ql, int qr, int l, int r, int id = 1) {
        if (qr < l || ql > r)
            return INT_MAX;
        if (ql <= l && qr >= r)
            return buf[id].val;
        int m = (r - l) / 2 + l;
        return op(dfs_query(ql, qr, l, m, id * 2), dfs_query(ql, qr, m + 1, r, id * 2 + 1));
    }

   public:
    segment_tree(int _n) : n(1 << (int)ceil(log2(_n))), buf(2 * n, {INT_MAX}) {
    }
    void update(int pos, Ty val) {
        dfs_update(pos, val, 0, n - 1);
    }
    Ty query(int l, int r) {
        return dfs_query(l, r, 0, n - 1);
    }
};