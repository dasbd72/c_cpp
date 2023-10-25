#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void test_case() {
    ll N;
    cin >> N;
    deque<ll> prefix(N + 1, 0);
    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    deque<ll> next_smaller(N + 1, N + 1);  // length of prefix, end of prefix sum
    deque<ll> next_le(N + 1, N + 1);
    deque<ll> stk;
    stk.push_back(0);
    for (ll i = 1; i <= N; i++) {
        while (!stk.empty() && prefix[stk.back()] > prefix[i]) {
            next_smaller[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    stk.push_back(0);
    for (ll i = 1; i <= N; i++) {
        while (!stk.empty() && prefix[stk.back()] <= prefix[i]) {
            next_le[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    ll ans = 0;
    ll l = 0;
    while (l < N) {
        ll max_r = next_smaller[l];
        ll r = l;
        while(next_le[r] < max_r) {
            r = next_le[r];
            ans = max(ans, r - l);
        }
        l = r + 1;
    }
    cout << ans << "\n";
}
void solve() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
