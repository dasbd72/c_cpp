#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

void test_case() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), less<ll>());

    auto check = [&](ll M) {
        vector<ll> d(N);
        for (int i = 0; i < N; i++)
            d[i] = a[i] + M * b[i];
        sort(d.begin(), d.end(), less<ll>());
        int i = 0, j = 0;
        while (i < K && j < N) {
            if (c[i] < d[j]) {
                i++, j++;
            } else {
                j++;
            }
        }
        return i != K;
    };

    if (check(numeric_limits<int>::max())) {
        cout << "-1\n";
    } else {
        auto [l, r] = binarySearch((ll)0, (ll)numeric_limits<int>::max(), check);
        cout << r << "\n";
    }
}
void solve() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}