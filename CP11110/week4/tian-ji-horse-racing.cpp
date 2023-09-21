#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename Func>
ll binarySearch(Func func, ll L, ll R) {
    if(!func(R)) {
        return -1;
    }
    while(L < R) {
        ll M = L + (R - L) / 2;
        if(func(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    return L;
}
void solve() {
    int N, K;
    vector<ll> A, B, C;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        A.emplace_back(a);
        B.emplace_back(b);
    }
    for (int i = 0; i < N; i++) {
        ll c;
        cin >> c;
        C.emplace_back(c);
    }
    sort(C.begin(), C.end(), greater<ll>());

    auto func = [&](int m) {
        int cnt = 0;
        vector<ll> newA;
        for (int i = 0; i < N; i++) {
            newA.emplace_back(A[i] + m * B[i]);
        }
        sort(newA.begin(), newA.end(), greater<ll>());
        int ai = 0, ci = 0;
        while (ai < N && ci < N) {
            if (newA[ai] > C[ci]) {
                cnt++;
                ai++;
                ci++;
            } else {
                ci++;
            }
        }
        return cnt >= K;
    };

    cout << binarySearch(func, 0, numeric_limits<int>::max()) << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}