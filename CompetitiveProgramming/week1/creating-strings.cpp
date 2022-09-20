#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int cnt[26] = {};
    int num = factorial(s.size());
    for(auto c : s) {
        cnt[c - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        num /= factorial(cnt[i]);
    }

    cout << num << "\n";
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}