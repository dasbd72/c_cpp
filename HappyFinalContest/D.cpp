#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s[3];
    vector<int> cnts;
    int tot = 0, cnt, tmp;
    int ans = 0;

    for (int i = 0; i < 3; i++) {
        cnt = 0;
        cin >> s[i];
        for (auto c : s[i]) {
            if (c == '1')
                cnt++, tot++;
        }
        cnts.emplace_back(cnt);
    }
    sort(cnts.begin(), cnts.end());
    int _3 = 0, _2 = 0, _1 = 0, _0;
    _3 = cnts[0];
    _2 = cnts[1] - _3;
    _1 = cnts[2] - _2 - _3;
    _0 = 10 - _3 - _2 - _1;
    while (_0) {
        if (_2)
            _2--, _1 += 2, _0--;
        else if (_3 && _0 >= 2)
            _3--, _1 += 3, _0 -= 2;
        else
            break;
    }
    for (int i = 0; i < 10; i++) {
        if (i < _3 + _1)
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 D.cpp ; ./a.out <D.in