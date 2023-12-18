#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    string s;
    cin >> s;
    vector<int> cnt(2, 0);
    vector<int> used(2, 0);
    for (auto c : s) {
        cnt[c - '0']++;
    }
    int cost = 0;
    for (int i = 0; cnt[0] || cnt[1];) {
        int bit = s[i] - '0';
        int inv = 1 - bit;
        if (cnt[inv]) {
            cnt[inv]--;
            i++;
        } else {
            cost++;
            cnt[bit]--;
        }
    }
    cout << cost << "\n";
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
