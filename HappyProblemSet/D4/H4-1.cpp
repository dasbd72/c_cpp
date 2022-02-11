#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;

    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            break;
        int cnt = 0;
        vector<int> CDJack, CDJill;
        for (int i = 0, x; i < N; i++) {
            cin >> x;
            CDJack.push_back(x);
        }
        for (int i = 0, x; i < N; i++) {
            cin >> x;
            CDJill.push_back(x);
        }
        auto itJack = CDJack.begin();
        auto itJill = CDJill.begin();
        cnt = 0;
        while (itJack != CDJack.end() && itJill != CDJill.end()) {
            if (*itJack == *itJill) {
                cnt++;
                ++itJack;
                ++itJill;
            } else if (*itJack < *itJill) {
                ++itJack;
            } else {
                ++itJill;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H4-1.cpp ; ./a.out <H4-1.in