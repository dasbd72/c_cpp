#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<vector<ll> > dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(n % 2 == 1)
            dp[i][i] = arr[i];
    }
    for (int l = n - 2; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            if ((n - (r - l + 1)) % 2 == 0) {
                dp[l][r] = max(arr[l] + dp[l + 1][r], arr[r] + dp[l][r - 1]);
            } else {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
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
