#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    const ll m = 1e9 + 7;
    ll m_two_inv = m / 2 + 1;
    while ((m_two_inv * 2) % m != 1)
        m_two_inv++;

    ll n;
    cin >> n;

    ll sum = 0;
    for (ll i = 1; i <= n;) {
        ll cnt = n / i;
        ll ni = n / cnt + 1;

        int mult = 1;
        mult = (mult * ((ni - i) % m)) % m;
        mult = (mult * ((i + ni - 1) % m)) % m;
        mult = (mult * (m_two_inv % m)) % m;
        mult = (mult * (cnt % m)) % m;
        sum = (sum + mult)%m;

        i = ni;
    }
    cout << sum << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
