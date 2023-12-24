#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    pair<ll, ll> best[1 << n];
    best[0] = make_pair(1, 0);
    for (int s = 1; s < (1 << n); s++) {
        best[s] = make_pair(n + 1, 0);
        for (int p = 0; p < n; p++) {
            if (!(s & (1 << p)))
                continue;
            auto opt = best[s & ~(1 << p)];
            if (opt.second + w[p] <= x) {
                opt.second += w[p];
            } else {
                opt.first++;
                opt.second = w[p];
            }
            best[s] = min(best[s], opt);
        }
    }
    cout << best[(1 << n) - 1].first << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
