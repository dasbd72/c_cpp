#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    int prefix[1001][1001] = {};
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == '.') {
                prefix[i + 1][j + 1] = prefix[i + 1][j];
            } else {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + 1;
            }
        }
    }
    while (Q--) {
        int y1, x1, y2, x2;
        int ans = 0;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i = y1; i <= y2; i++) {
            ans += prefix[i][x2] - prefix[i][x1 - 1];
        }
        cout << ans << "\n";
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-6.cpp ; ./a.out <T1-6.in