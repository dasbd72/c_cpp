#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)
        return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}
ll inv_mod(ll a, ll p) {
    auto [xp, yp] = extgcd(a, p);
    return xp;
}
void solve() {
    ll n;
    cin >> n;
    while (n--) {
        array<ll, 3> k;
        array<ll, 3> r;
        ll mult = 1;
        for (int i = 0; i < 3; i++) {
            cin >> k[i] >> r[i];
            mult = mult * k[i];
        }

        ll x = 0;
        for (int i = 0; i < 3; i++) {
            x += r[i] * inv_mod(mult / k[i], k[i]) * (mult / k[i]);
        }
        if (x > 0)
            x = x - (x / mult) * mult;
        else
            x = x - ((x - mult + 1) / mult) * mult;
        cout << x << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
