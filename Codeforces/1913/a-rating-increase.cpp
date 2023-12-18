#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    string s;
    cin >> s;
    for (auto c : s) {
        if (!isdigit(c)) {
            cout << "-1\n";
            return;
        }
    }
    for (int p = 1; p < (int)s.size(); p++) {
        string sa = s.substr(0, p);
        string sb = s.substr(p, (int)s.size() - p);
        if (sa[0] == '0' || sb[0] == '0')
            continue;

        int a = stoi(sa);
        int b = stoi(sb);
        if (!(a < b))
            continue;
        cout << a << " " << b << "\n";
        return;
    }
    cout << "-1\n";
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
