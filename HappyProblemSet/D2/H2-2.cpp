#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    vector<bool> existTB(200001, false);
    cin >> N;
    for (int i = 0, x; i < N - 1; i++) {
        cin >> x;
        existTB[x] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!existTB[i]) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-2.cpp ; ./a.out <H2-2.in