#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_VAL = 1000000;
const ll MOD_NUM = 1e9 + 7;
ll fast_power(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}
void solve() {
    vector<ll> factor(MAX_VAL + 1);
    vector<ll> inv_factor(MAX_VAL + 1);
    factor[0] = 1;
    inv_factor[0] = 1;
    for (int i = 1; i <= MAX_VAL; i++) {
        factor[i] = (factor[i - 1] * i) % MOD_NUM;
        inv_factor[i] = fast_power(factor[i], MOD_NUM - 2, MOD_NUM);
    }

    ll n;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << factor[a] * inv_factor[b] % MOD_NUM * inv_factor[a - b] % MOD_NUM << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
