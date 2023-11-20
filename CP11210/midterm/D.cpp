#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (check(R) == true)
        return {R, R + 1};
    if (check(L) == false)
        return {L - 1, L};
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
    int n, m;
    cin >> n >> m;
    m -= n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<ll>());

    auto check = [&](ll val) {
        int cm = m;
        for (auto c : arr) {
            cm -= ceil((double)c / val) - 1;
        }
        return cm < 0;
    };

    auto [l, r] = binarySearch((ll)1, arr[0], check);

    cout << r << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}