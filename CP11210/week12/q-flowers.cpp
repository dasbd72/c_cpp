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
        ll ret = 0;
        for (; x; x -= lowbit(x))
            ret = max(ret, buf[x]);
        return ret;
    }
    void modify(int x, ll val) {
        for (; x <= n; x += lowbit(x))
            buf[x] = max(buf[x], val);
    }
    ll maximum() {
        return *max_element(buf.begin() + 1, buf.end());
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1), w(n + 1);
    BIT bit;
    bit.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        // find the maximum sum among all less height
        bit.modify(h[i], bit.query(h[i] - 1) + w[i]);
    }
    cout << bit.maximum() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
