#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, a[3];
    cin >> n;
    vector<vector<int> > dp(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
        }
        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = a[j];
            }
        } else {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + a[j];
            }
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
