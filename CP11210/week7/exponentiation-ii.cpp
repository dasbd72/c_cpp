#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
ll fast_power(ll x, ll y, ll m) {
    ll ans = 1;
    while (y) {
        if (y & 1)
            ans = (ans * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        // a ^ p % p = a % p
        // b ^ c = r * (p-1) + q
        // a ^ (b ^ c) % p = a ^ ((b ^ c) % (p - 1)) % p
        cout << fast_power(a, fast_power(b, c, MOD - 1), MOD) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
