#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    ll X;
    vector<ll> vec;
    unordered_set<ll> psum_set;
    unordered_map<ll, ll> psum_cnt;
    ll psum = 0;
    ll cnt = 0;
    cin >> N >> X;
    psum_set.insert(0);
    psum_cnt[0] = 1;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        vec.emplace_back(x);
        psum += x;
        if (psum_set.find(psum - X) != psum_set.end())
            cnt += psum_cnt[psum - X];
        psum_set.insert(psum);
        if (psum_cnt.find(psum) != psum_cnt.end()) {
            psum_cnt[psum]++;
        } else {
            psum_cnt[psum] = 1;
        }
    }
    cout << cnt << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2