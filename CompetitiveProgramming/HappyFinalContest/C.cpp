#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (2 * pow(3, (m + n + 1) % 2) * pow(2, (m + n + 1) % 2)) << "\n";
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
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 C.cpp ; ./a.out <C.in