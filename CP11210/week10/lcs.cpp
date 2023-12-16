#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string LCS(string a, string b) {
    int len_a = a.size(), len_b = b.size();
    vector<vector<int> > dp_mat(len_a, vector<int>(len_b, 0));
    auto dp_mat_ref = [&](int m, int n) {
        if (m < 0 || n < 0)
            return 0;
        return dp_mat[m][n];
    };
    for (int m = 0; m < len_a; m++) {
        for (int n = 0; n < len_b; n++) {
            if (a[m] == b[n]) {
                dp_mat[m][n] = dp_mat_ref(m - 1, n - 1) + 1;
            } else {
                if (dp_mat_ref(m - 1, n) > dp_mat_ref(m, n - 1)) {
                    dp_mat[m][n] = dp_mat_ref(m - 1, n);
                } else {
                    dp_mat[m][n] = dp_mat_ref(m, n - 1);
                }
            }
        }
    }

    string ans;
    int m = len_a - 1, n = len_b - 1;
    while (m >= 0 && n >= 0) {
        if (a[m] == b[n]) {
            ans = a[m] + ans;
            m--, n--;
        } else {
            if (dp_mat_ref(m - 1, n) > dp_mat_ref(m, n - 1)) {
                m--;
            } else {
                n--;
            }
        }
    }
    return ans;
}
void solve() {
    string a, b;
    cin >> a >> b;
    string ans = LCS(a, b);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
