#include <bits/stdc++.h>
using namespace std;
string getShiftedString(string& s, int pos) {
    return s.substr(pos, s.length() - pos) + s.substr(0, pos);
}
int getMinPos(string& s, int l, int r) {
    if (l == r - 1)
        return l;
    int m, lval, rval;
    m = (l + r) / 2;
    lval = getMinPos(s, l, m);
    rval = getMinPos(s, m, r);
    if (getShiftedString(s, lval) < getShiftedString(s, rval))
        return lval;
    else
        return rval;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    int T;
    cin >> T;
    while (T--) {
        cin >> S;
        cout << getShiftedString(S, getMinPos(S, 0, S.length())) << "\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-3.cpp ; ./a.out <H2-3.in