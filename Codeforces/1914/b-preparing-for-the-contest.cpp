#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n; i >= k + 2; i--) {
        cout << i << " ";
    }
    for (int i = 1; i <= k + 1; i++) {
        cout << i << " ";
    }
    cout << "\n";
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
