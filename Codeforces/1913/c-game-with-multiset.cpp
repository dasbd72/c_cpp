#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int m, t, x;
    cin >> m;
    vector<ll> cnt(30, 0);
    while (m--) {
        cin >> t >> x;
        if (t == 1) {
            cnt[x]++;
        } else {
            bool available = true;
            vector<ll> tmp = cnt;
            ll sum = 0;
            for (int i = 0; x > 0; i++) {
                if (x & 1) {
                    if (tmp[i] > 0)
                        tmp[i]--;
                    else if (sum >= (1 << i))
                        sum -= (1 << i);
                    else {
                        available = false;
                        break;
                    }
                }
                sum += tmp[i] * (1 << i);
                x >>= 1;
            }
            if (available)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
