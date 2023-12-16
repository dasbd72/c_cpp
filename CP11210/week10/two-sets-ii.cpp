#include <bits/stdc++.h>
using namespace std;

#define MOD (int)(1e9 + 7)
typedef long long ll;
void solve() {
    int n, target;
    cin >> n;
    target = n * (n + 1) / 2;
    if (target % 2) {
        cout << 0 << "\n";
        return;
    }
    target /= 2;
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int sum = target; sum >= 0; sum--) {
            if (sum + i > target)
                continue;
            dp[sum + i] = (dp[sum + i] + dp[sum]) % MOD;
        }
    }

    dp[target] = (dp[target] * 500000004) % MOD;
    cout << dp[target] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
