#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int lowbit(int x) {
    return x & -x;
}

/* 1-based */
class BIT {
    int n;
    vector<ll> buf;

   public:
    void init(int _n) {
        n = _n;
        buf.resize(n + 1);
    }
    ll query(int x) const {
        ll sum = 0;
        for (; x; x -= lowbit(x))
            sum += buf[x];
        return sum;
    }
    void modify(int x, ll val) {
        for (; x <= n; x += lowbit(x))
            buf[x] += val;
    }
};

/* 1-based */
class BIT2D {
    int m;
    vector<BIT> buf1d;

   public:
    void init(int _m, int _n) {
        m = _m;
        buf1d.resize(m + 1);
        for (auto& b : buf1d) b.init(_n);
    }
    ll query(int y, int x) const {
        ll sum = 0;
        for (; y; y -= lowbit(y))
            sum += buf1d[y].query(x);
        return sum;
    }
    void modify(int y, int x, ll val) {
        for (; y <= m; y += lowbit(y))
            buf1d[y].modify(x, val);
    }
    ll range(int y1, int x1, int y2, int x2) {
        y1--, x1--;
        ll sum = query(y2, x2);
        sum -= query(y2, x1);
        sum -= query(y1, x2);
        sum += query(y1, x1);
        return sum;
    }
};

class RangeBIT {
    int n;
    BIT d, xd;

   public:
    void init(int _n) {
        n = _n;
        d.init(n);
        xd.init(n);
    }
    ll query(int x) const {
        return (x + 1) * d.query(x) - xd.query(x);
    }
    void modify(int ql, int qr, ll val) {
        d.modify(ql, val);
        xd.modify(ql, ql * val);
        if (qr < n) {
            d.modify(qr + 1, -val);
            xd.modify(qr + 1, -(qr + 1) * val);
        }
    }
};
