#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > grid_t;

int block_min(grid_t& grid, int r, int c) {
    if (r - 1 >= 0 && c - 1 >= 0) {
        return grid[r - 1][c - 1];
    }
    return 0;
}
int block_max(grid_t& grid, int r, int c) {
    int ret = 1;
    for (int rr = r - 1; rr < r + 2; rr++) {
        if (rr < 0 || rr >= (int)grid.size())
            continue;
        for (int cc = c - 1; cc < c + 2; cc++) {
            if (cc < 0 || cc >= (int)grid[0].size())
                continue;
            ret = min(grid[rr][cc], ret);
        }
    }
    return ret;
}
void modify(grid_t& grid, int r, int c, int cnt) {
    for (int rr = r - 1; rr < r + 2; rr++) {
        if (rr < 0 || rr >= (int)grid.size())
            continue;
        for (int cc = c - 1; cc < c + 2; cc++) {
            if (cc < 0 || cc >= (int)grid[0].size())
                continue;
            grid[rr][cc] += cnt;
        }
    }
}
int check(grid_t& grid) {
    for (int r = 0; r < (int)grid.size(); r++) {
        for (int c = 0; c < (int)grid[0].size(); c++) {
            if (grid[r][c])
                return 0;
        }
    }
    return 1;
}
int dfs(grid_t& grid, int r, int c) {
    if (r >= (int)grid.size()) {
        if (check(grid))
            return 1;
        else
            return 0;
    }

    int from = block_min(grid, r, c);
    int to = block_max(grid, r, c);

    int ret = 0;
    int nr = r, nc = c + 1;
    if (nc >= (int)grid[0].size())
        nr++, nc = 0;

    for (int i = from; i <= to; i++) {
        modify(grid, r, c, -i);
        ret += dfs(grid, nr, nc);
        modify(grid, r, c, i);
    }

    return ret;
}
void solve() {
    int n, m;
    cin >> n >> m;
    grid_t grid(n, vector<int>(m));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> grid[r][c];
        }
    }

    cout << dfs(grid, 0, 0) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}