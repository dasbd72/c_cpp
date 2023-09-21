#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S, T;
    while (cin >> S >> T) {
        while (!S.empty() && !T.empty()) {
            if (*prev(S.end()) == *prev(T.end())) {
                T.pop_back();
                S.pop_back();
            } else {
                T.pop_back();
            }
        }
        if (S.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-4.cpp ; ./a.out <H2-4.in