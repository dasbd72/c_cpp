#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool check(string s) {
    char prev = 0;
    for (auto c : s) {
        if (c == prev)
            return false;
        prev = c;
    }
    return true;
}
bool check2(string s, string t) {
    char prev = 0;
    int len = (int)s.length();
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == prev)
            s = s.substr(0, i + 1) + t + s.substr(i + 1, (int)s.length() - i - 1);
        prev = s[i];
    }
    return check(s);
}
void test_case() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if (check2(s, t))
        cout << "YES\n";
    else
        cout << "NO\n";
}
void solve() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
