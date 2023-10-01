#include <bits/stdc++.h>
using namespace std;

int dr[][6] = {{0, 1, 1, 0, -1, -1}, {0, 1, 1, 0, -1, -1}};
int dc[][6] = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}};

void recursive(int R, int C, const vector<int>& weight, const vector<pair<int, int> >& pos, int& ans, int current, vector<int>& grid, int phase, int r, int c, int prev_dir) {
    for (int i = 0; i < 6; i++) {
        if (prev_dir != -1 && i != prev_dir && i != (prev_dir + 1) % 6 && i != (prev_dir + 5) % 6) {
            continue;
        }
        int nr = r + dr[r % 2][i];
        int nc = c + dc[r % 2][i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;

        if (nr == pos[phase * 2 + 1].first && nc == pos[phase * 2 + 1].second) {
            if (phase == 1) {
                ans = min(ans, current);
            } else {
                recursive(R, C, weight, pos, ans, current, grid, 1, pos[2].first, pos[2].second, -1);
            }
        } else {
            if (grid[nr * C + nc])
                continue;
            grid[nr * C + nc] = 1;
            recursive(R, C, weight, pos, ans, current + weight[nr * C + nc], grid, phase, nr, nc, i);
            grid[nr * C + nc] = 0;
        }
    }
}
void find_cost(int R, int C, const vector<int>& weight, const vector<pair<int, int> >& pos, int& ans) {
    vector<int> grid(weight.size(), 0);
    int init_weight = 0;
    for (int i = 0; i < 4; i++) {
        init_weight += weight[pos[i].first * C + pos[i].second];
        grid[pos[i].first * C + pos[i].second] = 1;
    }
    recursive(R, C, weight, pos, ans, init_weight, grid, 0, pos[0].first, pos[0].second, -1);
}
void test_case() {
    int R, C;
    cin >> R >> C;
    vector<pair<int, int> > pos(4);
    vector<int> weight(R * C);
    for (int i = 0; i < 4; i++) {
        cin >> pos[i].first >> pos[i].second;
        pos[i].first--;
        pos[i].second--;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> weight[i * C + j];
        }
    }

    int ans = INT32_MAX;
    find_cost(R, C, weight, pos, ans);
    if (ans == INT32_MAX)
        ans = -1;

    cout << ans << "\n";
}
void solve() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}