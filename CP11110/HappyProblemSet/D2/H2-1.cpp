#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    int ans;
    while (cin >> S) {
        if (S == "END")
            break;
        if (S == "1")
            ans = 1;
        else if (S.length() <= 1)
            ans = 2;
        else if (S.length() <= 9)
            ans = 3;
        else
            ans = 4;
        cout << ans << "\n";
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-1.cpp ; ./a.out <H2-1.in