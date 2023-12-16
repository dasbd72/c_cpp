#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int ed(string a, string b) {
    int len_a = a.size(), len_b = b.size();
    vector<vector<int> > dp(len_a, vector<int>(len_b, 0));
    auto dp_ref = [&](int m, int n) {
        if (m < 0 || n < 0) {
            return max(m + 1, n + 1);
        }
        return dp[m][n];
    };
    for (int m = 0; m < len_a; m++) {
        for (int n = 0; n < len_b; n++) {
            if (a[m] == b[n]) {
                dp[m][n] = dp_ref(m - 1, n - 1);
            } else {
                dp[m][n] = min(dp_ref(m - 1, n - 1), min(dp_ref(m - 1, n), dp_ref(m, n - 1))) + 1;
            }
        }
    }
    return dp_ref(len_a - 1, len_b - 1);
}
void solve() {
    string a, b;
    cin >> a >> b;
    cout << ed(a, b) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
