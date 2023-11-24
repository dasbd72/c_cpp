#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_VAL = 1e6;
void solve() {
    int n;
    cin >> n;
    vector<int> num(MAX_VAL + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[x]++;
    }

    for (int gcd = MAX_VAL; gcd > 0; gcd--) {
        int cnt = 0;
        for (int j = gcd; j <= MAX_VAL; j += gcd) cnt += num[j];

        if (cnt >= 2) {
            cout << gcd << "\n";
            break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
