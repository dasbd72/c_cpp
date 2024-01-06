#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
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
