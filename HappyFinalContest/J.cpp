#include <bits/stdc++.h>
using namespace std;
int same(int n, int *row1, int *row2) {
    sort(row1, row1 + n);
    sort(row2, row2 + n);
    int i1 = 0, i2 = 0, res = 0;
    while (i1 < n && i2 < n) {
        if (row1[i1] == row2[i2]) {
            res++, i1++, i2++;
        } else if (row1[i1] < row2[i2]) {
            i1++;
        } else {
            i2++;
        }
    }
    return res;
}
void solve() {
    int N, M, ans = 0;
    int grid[1000][1000];
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> grid[r][c];
        }
    }
    for (int r = 1; r < N; r++) {
        ans += same(M, grid[r - 1], grid[r]);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 J.cpp ; ./a.out <J.in