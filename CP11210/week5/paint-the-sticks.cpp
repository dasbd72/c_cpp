#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    stack<ll> stk;
    while (cin >> n) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll h;
            cin >> h;

            ll tot = 0, cnt = 0, cur = 0;
            while (!stk.empty() && stk.top() > h) {
                cnt += 1;
                cur = stk.top();
                ans = max(ans, cnt * cur);

                stk.pop();
                tot++;
            }
            while (tot--) {
                stk.push(h);
            }
            stk.push(h);
        }
        ll cnt = 0, cur = 0;
        while (!stk.empty()) {
            cnt += 1;
            cur = stk.top();
            ans = max(ans, cnt * cur);

            stk.pop();
        }
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}