#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int lowbit(int x) {
    return x & -x;
}
inline int lg(int x) {
    switch (x) {
        case 1:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 8:
            return 3;
        case 16:
            return 4;
        case 32:
            return 5;
        case 64:
            return 6;
        case 128:
            return 7;
        default:
            return -1;
    }
}
void solve() {
    int k;
    cin >> k;

    int fact[10];
    int factCnt = 0;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            int cnt = 0;
            while (k % i == 0)
                k /= i, cnt++;
            fact[factCnt++] = cnt;
        }
    }
    if (k > 1)
        fact[factCnt++] = 1;

    int allMult = 1;
    for (int i = 0; i < (int)factCnt; i++) {
        allMult *= fact[i] + 1;
    }

    auto getMult = [&](int subset) {
        int mult = allMult;
        while (subset) {
            int i = lg(lowbit(subset));
            subset ^= lowbit(subset);
            mult /= fact[i] + 1;
            mult *= -fact[i];
        }
        return mult;
    };

    int ans = 0;
    int bound = 1 << factCnt;
    for (int subset = 0; subset < bound; subset++) {
        int mult = getMult(subset);
        ans += mult * mult * mult;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}