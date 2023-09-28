#include <bits/stdc++.h>
using namespace std;

const int dc[] = {0, 0, 1, -1};
const int dr[] = {-1, 1, 0, 0};
const char ddir[] = {'U', 'D', 'R', 'L'};

int dir_to_int(char dir) {
    switch (dir) {
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'R':
            return 2;
        case 'L':
            return 3;
        default:
            return -1;
    }
}
long long refer_grid(int r, int c, long long grid) {
    return 1 & (grid >> (r * 7 + c));
}
long long set_grid(int r, int c, long long grid) {
    return grid | ((long long)1 << (r * 7 + c));
}
bool available(int r, int c, int d, long long grid) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (nr >= 0 && nr <= 6 && nc >= 0 && nc <= 6 && !refer_grid(nr, nc, grid))
        return true;
    else
        return false;
}
int recursive(int idx, string& path, long long grid, int r, int c) {
    if (idx == (int)path.length()) {
        if (r == 6 && c == 0)
            return 1;
        return 0;
    }
    if (r == 6 && c == 0)
        return 0;

    if (idx > 0) {
        // Core solution
        int d = dir_to_int(path[idx - 1]);
        if ((d == 0 || d == 1) && !available(r, c, d, grid) && available(r, c, 2, grid) && available(r, c, 3, grid))
            return 0;
        else if ((d == 2 || d == 3) && !available(r, c, d, grid) && available(r, c, 0, grid) && available(r, c, 1, grid))
            return 0;
    }

    int solutions = 0;
    if (path[idx] != '?') {
        int d = dir_to_int(path[idx]);
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nr <= 6 && nc >= 0 && nc <= 6 && !refer_grid(nr, nc, grid)) {
            solutions += recursive(idx + 1, path, set_grid(nr, nc, grid), nr, nc);
        }
    } else {
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr <= 6 && nc >= 0 && nc <= 6 && !refer_grid(nr, nc, grid)) {
                path[idx] = ddir[d];
                solutions += recursive(idx + 1, path, set_grid(nr, nc, grid), nr, nc);
                path[idx] = '?';
            }
        }
    }
    return solutions;
}
void solve() {
    string path;
    cin >> path;
    long long grid = set_grid(0, 0, 0);
    int solutions = recursive(0, path, grid, 0, 0);
    cout << solutions << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}