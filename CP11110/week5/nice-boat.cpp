#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> prefix_sum(N + 1);
        prefix_sum[0] = 0;
        for (int i = 1; i <= N; i++) {
            ll x;
            cin >> x;
            prefix_sum[i] = prefix_sum[i - 1] + x;
        }

        deque<ll> next_smaller_stk;
        vector<ll> next_smaller(N + 1);
        for (int i = 0; i < N + 1; i++) {
            next_smaller[i] = N + 1;
            while (!next_smaller_stk.empty() && prefix_sum[i] < prefix_sum[next_smaller_stk.back()]) {
                next_smaller[next_smaller_stk.back()] = i;
                next_smaller_stk.pop_back();
            }
            next_smaller_stk.emplace_back(i);
        }
        deque<ll> next_larger_stk;
        vector<ll> next_larger(N + 1);
        for (int i = 0; i < N + 1; i++) {
            next_larger[i] = N + 1;
            while (!next_larger_stk.empty() && prefix_sum[i] >= prefix_sum[next_larger_stk.back()]) {
                next_larger[next_larger_stk.back()] = i;
                next_larger_stk.pop_back();
            }
            next_larger_stk.emplace_back(i);
        }

        ll max_ans = 0;
        ll l = 0;
        while (l < N) {
            ll max_r = next_smaller[l];
            ll r = l;
            while (next_larger[r] < max_r && r != next_larger[r]) {
                r = next_larger[r];
            }
            max_ans = max(max_ans, r - l);
            l = r + 1;  // No using max_r
        }
        cout << max_ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}