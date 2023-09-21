#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll A, B, C, D, M, S, T;
    cin >> A >> B >> C >> D;
    cin >> M >> S >> T;

    ll l = 1, r = T + 1;
    ll best_T = 1e9;
    ll best_dist = 0;
    while (l < r) {
        ll m = l + (r - l) / 2;
        bool larger = true;
        for (int i = 0; i < m; i++) {
            ll fuel = M + i * D;
            ll remt = m - i;
            ll dist = 0;
            ll bt = min(fuel / C, remt);
            ll at = remt - bt;
            dist = bt * B + at * A;
            if (dist >= S) {
                larger = false;
                best_T = min(best_T, m);
            } else {
                best_dist = max(best_dist, dist);
            }
        }
        if (larger)
            l = m + 1;
        else
            r = m;
    }
    if (best_T <= T)
        cout << "Yes\n"
             << best_T << "\n";
    else
        cout << "No\n"
             << best_dist << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}