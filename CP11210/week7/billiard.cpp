#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}
pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)
        return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}
void solve2() {
    ll n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;

    // At point
    if ((x == 0 && y == 0) ||
        (x == n && y == 0) ||
        (x == 0 && y == m) ||
        (x == n && y == m)) {
        cout << x << " " << y << "\n";
        return;
    }

    if (vx == 0 && vy == 0) {
        cout << "-1\n";
        return;
    }

    // Single way
    if (vx * vy == 0) {
        if (vx == 0) {
            if (x == 0 || x == n) {
                cout << x << " " << (vy > 0 ? m : 0) << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            if (y == 0 || y == m) {
                cout << (vx > 0 ? n : 0) << " " << y << "\n";
            } else {
                cout << "-1\n";
            }
        }
        return;
    }

    // make direction positive
    ll flipx = 0, flipy = 0;
    if (vx < 0) {
        x = n - x;
        flipx = 1;
    }
    if (vy < 0) {
        y = m - y;
        flipy = 1;
    }

    // x + c = an
    // y + c = bm
    // an - bm = x - y
    ll g = gcd(n, m);
    if ((x - y) % g != 0) {
        cout << "-1\n";
    } else {
        auto [a, b] = extgcd(n, m);
        ll t = (x - y) / g;
        a *= t;
        b *= t;

        ll _m = m / g, _n = n / g;
        ll _a = (a % _m + _m + _m - 1) % _m + 1, _b = -((x - y) - _a * n) / m;
        ll p = 0, q = 0;
        if (_a % 2)
            p = n;
        if (_b % 2)
            q = m;
        if (flipx)
            p = n - p;
        if (flipy)
            q = m - q;
        cout << p << " " << q << "\n";
    }
}
void solve() {
    int T;
    cin >> T;
    while (T--)
        solve2();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
