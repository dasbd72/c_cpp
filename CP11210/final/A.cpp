#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> p(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    vector<int> dp(1000001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j < p[i])
                continue;
            dp[j] |= dp[j - p[i]];
        }
    }
    ll ans = 0x7fffffff;
    for (ll j = 0; j <= sum; j++) {
        if (dp[j])
            ans = min(sum - j - j > 0 ? sum - j - j : -(sum - j - j), ans);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
