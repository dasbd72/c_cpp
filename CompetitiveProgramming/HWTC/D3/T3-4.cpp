#include <bits/stdc++.h>
using namespace std;
#define MAX 0x7ffffff
int dp[501][501] = {};
int run(int w, int h) {
    if (dp[w][h] != MAX)
        return dp[w][h];
    int result = MAX;
    if (w == h) {
        result = 0;
    } else {
        for (int i = 1; i < w; i++)
            result = min(result, run(i, h) + run(w - i, h) + 1);
        for (int i = 1; i < h; i++)
            result = min(result, run(w, i) + run(w, h - i) + 1);
    }
    return dp[w][h] = dp[h][w] = result;
}
void solve() {
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++) dp[i][j] = MAX;
    int A, B;
    cin >> A >> B;
    cout << run(A, B) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T3-4.cpp ; ./a.out <T3-4.in