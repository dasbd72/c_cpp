#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    // lower_bound(x): find element >= x
    // upper_bound(x): find element > x
    // if multiple at position p, always operate on the last one

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    int err = 0;
    set<int> s;
    map<int, int> cnt;

    auto pop = [&](int p) {
        cnt[p]--;
        if (cnt[p] == 0)
            s.erase(p);

        auto lit = s.upper_bound(p - k);
        if (lit != s.end() && *lit <= p) {
            err--;
        }
        auto rit = s.upper_bound(p);
        if (rit != s.end() && *rit < p + k) {
            err--;
            if(rit != s.begin() && *rit < *(--rit) + k)
                err++;
        }

        return err > 0;
    };
    auto push = [&](int p) {
        auto lit = s.upper_bound(p - k);
        if (lit != s.end() && *lit <= p) {
            err++;
        }
        auto rit = s.upper_bound(p);
        if (rit != s.end() && *rit < p + k) {
            err++;
            if(rit != s.begin() && *rit < *(--rit) + k)
                err--;
        }

        s.insert(p);
        cnt[p]++;
        return err > 0;
    };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }

    int q;
    cin >> q;
    while (q--) {
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            if (pop(p))
                cout << "QQ\n";
            else
                cout << "OuOb\n";
        } else {
            if (push(p))
                cout << "QQ\n";
            else
                cout << "OuOb\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}