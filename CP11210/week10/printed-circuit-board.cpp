#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    sort(pairs.begin(), pairs.end());

    int ans = 0;
    vector<int> dp(n, 0);
    vector<int> v;

    // find last > x
    auto bs = [&](int x) {
        int l = 0, r = v.size();
        if (l + 1 > r || v[l] < x)
            return l - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (v[m] < x) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    };

    // longest decreasing subsequent
    for (int i = 0; i < n; i++) {
        int j = bs(pairs[i].second) + 1;
        dp[i] = j;
        if ((int)v.size() == j)
            v.emplace_back(pairs[i].second);
        else
            v[j] = max(v[j], pairs[i].second);

        ans = max(ans, dp[i] + 1);
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
