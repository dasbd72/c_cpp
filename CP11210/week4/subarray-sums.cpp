#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    ll n, target, a, ans = 0;
    cin >> n >> target;
    vector<pair<ll, ll> > b(n + 1);
    b[0].first = b[0].second = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        b[i].first = a + b[i - 1].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    for (int i = n; i >= 1; i--) {
        int lower, upper, l, r;
        l = 0, r = i;
        while (l < r) {
            int m = (l + r) / 2;
            if (b[i].first - b[m].first > target)
                l = m + 1;
            else
                r = m;
        }
        lower = l;

        l = 0, r = i;
        while (l < r) {
            int m = (l + r) / 2;
            if (b[i].first - b[m].first >= target)
                l = m + 1;
            else
                r = m;
        }
        upper = l;

        if (upper > lower) {
            l = lower, r = upper;
            while (l < r) {
                int m = (l + r) / 2;
                if (b[i].second > b[m].second)
                    l = m + 1;
                else
                    r = m;
            }
            ans += l - lower;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}