#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, B;
    string S;
    vector<int> Hpos, Apos;
    cin >> N >> B >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A')
            Apos.emplace_back(i);
        else if (S[i] == 'H')
            Hpos.emplace_back(i);
    }
    for (int i = 0, x, y, c; i < B; i++) {
        cin >> x >> y >> c;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 A.cpp ; ./a.out <A.in