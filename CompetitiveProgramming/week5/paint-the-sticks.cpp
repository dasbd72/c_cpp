#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
void solve() {
    int N;
    while (cin >> N) {
        ll ans = 0;
        ll x;
        stack<pll> stk;
        int cnt;

        for (int i = 0; i < N; i++) {
            cnt = 0;
            cin >> x;

            while (!stk.empty() && x < stk.top().first) {
                pll val = stk.top();
                stk.pop();
                cnt += val.second;
                ans = max(ans, val.first * cnt);
            }

            if (!stk.empty() && stk.top().first == x) {
                pll val = stk.top();
                stk.pop();
                stk.emplace(x, val.second + cnt + 1);
            } else {
                stk.emplace(x, cnt + 1);
            }
        }

        cnt = 0;
        while (!stk.empty()) {
            pll val = stk.top();
            stk.pop();
            cnt += val.second;
            ans = max(ans, val.first * cnt);
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