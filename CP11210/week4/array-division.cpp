#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    while (L + 1 < R) {
        Ty Mid = L + (R - L) / 2;
        if (check(Mid))
            L = Mid;
        else
            R = Mid;
    }
    return {L, R};
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](ll val) {
        ll sum = 0;
        ll parts = 1;
        for (auto x : a) {
            if (x > val)
                return true;
            if (sum + x > val)
                sum = x, parts++;
            else
                sum += x;
        }
        return parts > k;
    };

    auto [L, R] = binarySearch((ll)0, (ll)1e18, check);
    cout << R << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}