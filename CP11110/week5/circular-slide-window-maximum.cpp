#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N, K;
    cin >> N >> K;
    vector<ll> num(N + K - 1);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = N; i < N + K - 1; i++) {
        num[i] = num[i - N];
    }
    deque<ll> dq;
    vector<ll> ans;
    for (int i = 0; i < N + K - 1; i++) {
        while (dq.size() && dq.front() <= i - K) {
            dq.pop_front();
        }
        while (dq.size() && num[dq.back()] < num[i]) {
            dq.pop_back();
        }
        dq.emplace_back(i);
        if (i >= K - 1) {
            ans.emplace_back(num[dq.front()]);
        }
    }
    for (auto n : ans) {
        cout << n << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}