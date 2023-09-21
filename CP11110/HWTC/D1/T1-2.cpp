#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool board[8][8] = {};
bool horizontal[8] = {};
bool pos_slope[15] = {};
bool neg_slope[15] = {};

void dfs(int pos) {
    if (pos == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (!board[pos][i] && !horizontal[i] && !pos_slope[pos + i] && !neg_slope[i - pos + 7]) {
            horizontal[i] = true;
            pos_slope[pos + i] = true;
            neg_slope[i - pos + 7] = true;
            dfs(pos + 1);
            horizontal[i] = false;
            pos_slope[pos + i] = false;
            neg_slope[i - pos + 7] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string inp;
    for (int i = 0; i < 8; i++) {
        cin >> inp;
        for (int j = 0; j < 8; j++) {
            if (inp[j] == '*')
                board[i][j] = true;
        }
    }
    dfs(0);
    cout << ans << "\n";

    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-2.cpp ; ./a.out <T1-2.in