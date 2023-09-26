#include <bits/stdc++.h>
using namespace std;

int factorial(int x) {
    if (x == 0)
        return 1;
    return x * factorial(x - 1);
}
int count(string s) {
    int cnt = factorial(s.length());
    int prev_i = 0;
    char prev = s[0];
    int i = 1;
    while (i < s.length()) {
        if (s[i] != prev) {
            cnt /= factorial(i - prev_i);
            prev_i = i;
            prev = s[i];
        }
        i++;
    }
    cnt /= factorial(i - prev_i);
    return cnt;
}
void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    cout << count(s) << "\n";
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}