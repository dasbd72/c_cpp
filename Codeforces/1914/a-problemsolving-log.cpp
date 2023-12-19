#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(26);
    for (int i = 0; i < 26; i++) {
        p[i] = i + 1;
    }
    for (auto c : s) {
        if (p[c - 'A'])
            p[c - 'A']--;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (p[i] == 0)
            ans++;
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
