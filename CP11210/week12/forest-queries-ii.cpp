#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int lowbit(int x) {
    return x & -x;
}

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
void solve() {
    int n, q;
    cin >> n >> q;

    BIT2D bit;
    bit.init(n, n);

    for (int y = 0; y < n; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < n; x++) {
            if (s[x] == '*')
                bit.modify(y + 1, x + 1, 1);
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int y, x;
            cin >> y >> x;
            if (bit.range(y, x, y, x))
                bit.modify(y, x, -1);
            else
                bit.modify(y, x, 1);
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << bit.range(y1, x1, y2, x2) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
