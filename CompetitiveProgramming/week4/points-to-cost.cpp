#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double cost(vector<ll>& X, ll costY, double p) {
    double ret = costY;
    for (auto x : X) {
        ret += (p - x) * (p - x);
    }
    return ret;
}
double ternary(vector<ll>& X, ll costY, double l, double r, double eps) {
    while (l + eps < r) {
        double ml = l + (r - l) / 3;
        double mr = r - (r - l) / 3;
        if (cost(X, costY, ml) > cost(X, costY, mr))
            l = ml;
        else
            r = mr;
    }
    return l;
}
void solve() {
    ll N, C, costY = 0, minX = numeric_limits<ll>::min(), maxX = numeric_limits<ll>::max();
    vector<ll> X;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        X.emplace_back(x);
        minX = min(x, minX);
        maxX = max(x, maxX);
        costY += (C - y) * (C - y);
    }
    cout << fixed << setprecision(10) << cost(X, costY, ternary(X, costY, minX, maxX, 1e-9)) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}