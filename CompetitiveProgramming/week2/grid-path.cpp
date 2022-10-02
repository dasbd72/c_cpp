#include <bits/stdc++.h>
using namespace std;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool grid[7][7];
int seq[50];
int ans;
bool availible(int r, int c, int d) {
    int nr, nc;
    nr = r + dr[d];
    nc = c + dc[d];
    if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && !grid[nr][nc]) {
        return true;
    }
    return false;
}
void dfs(int si, int r, int c, int prevd) {
    if (si == 48) {
        if (r == 6 && c == 0)
            ++ans;
        return;
    }
    if (r == 6 && c == 0) {  // 1st
        return;
    }
    if ((prevd == 0 && !availible(r, c, 0)) || (prevd == 2 && !availible(r, c, 2))) {
        if (availible(r, c, 1) && availible(r, c, 3))
            return;
    }
    if ((prevd == 1 && !availible(r, c, 1)) || (prevd == 3 && !availible(r, c, 3))) {
        if (availible(r, c, 0) && availible(r, c, 2))
            return;
    }

    int nr, nc, d;
    if (seq[si] != -1) {
        d = seq[si];
        nr = r + dr[d];
        nc = c + dc[d];
        if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && !grid[nr][nc]) {
            grid[nr][nc] = true;
            dfs(si + 1, nr, nc, d);
            grid[nr][nc] = false;
        }
    } else {
        for (d = 0; d < 4; d++) {
            nr = r + dr[d];
            nc = c + dc[d];
            if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && !grid[nr][nc]) {
                grid[nr][nc] = true;
                dfs(si + 1, nr, nc, d);
                grid[nr][nc] = false;
            }
        }
    }
}
void solve() {
    string S;
    cin >> S;
    for (int i = 0; i < 48; i++) {
        if (S[i] == '?')
            seq[i] = -1;
        else if (S[i] == 'U')
            seq[i] = 0;
        else if (S[i] == 'R')
            seq[i] = 1;
        else if (S[i] == 'D')
            seq[i] = 2;
        else if (S[i] == 'L')
            seq[i] = 3;
    }
    ans = 0;
    grid[0][0] = 1;
    dfs(0, 0, 0, -1);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2