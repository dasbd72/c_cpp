#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cmp {
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first * a.second != b.first * b.second)
            return a.first * a.second < b.first * b.second;
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};
ll score(int N, vector<pair<ll, ll>> &vec) {
    ll maxVal = 0;
    for (int i = 0; i < N; i++) {
        maxVal = max(maxVal, vec[i].first * vec[i].second);
    }
    return maxVal;
}
void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> F[i];
    sort(A.begin(), A.end(), less<ll>());
    sort(F.begin(), F.end(), greater<ll>());

    auto check = [&](ll K, ll target) {
        for (int i = 0; i < N; i++) {
            K -= A[i] - target / F[i];
            if (K < 0)
                return false;
        }
        return true;
    };

    ll l = 0, r = 1e15;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (check(K, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}