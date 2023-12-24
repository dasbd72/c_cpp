#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> sum(n);
    for (int i = 0; i < n; i++) {
        cin >> sum[i];
        if (i > 0)
            sum[i] += sum[i - 1];
    }

    vector<vector<ll> > dp(n, vector<ll>(n, 0x7ffffffffffff));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            ll cost = sum[j];
            if (i > 0)
                cost -= sum[i - 1];
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
