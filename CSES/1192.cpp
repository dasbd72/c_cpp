#include <bits/stdc++.h>
using namespace std;
int dc[] = {0, 1, 0, -1};
int dr[] = {-1, 0, 1, 0};
char grid[1002][1002] = {};
void dfs(int r, int c) {
    grid[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        int nxt_r = r + dr[i];
        int nxt_c = c + dc[i];
        if (grid[nxt_r][nxt_c] == '.')
            dfs(nxt_r, nxt_c);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, ans = 0;
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] == '.') {
                ans++;
                dfs(r, c);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 1192.cpp ; ./a.out <1192.in