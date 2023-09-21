#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> grid_t;
int dc[] = {0, 0, 1, -1};
int dr[] = {1, -1, 0, 0};
void solve() {
    grid_t grid(8, vector<int>(8, 11));
    for (int r = 1; r <= 6; r++) {
        for (int c = 1; c <= 6; c++) {
            cin >> grid[r][c];
        }
    }
    vector<int> car_dir(11, -1);
    vector<int> car_len(11, 0);
    for (int r = 1; r <= 6; r++) {
        for (int c = 1; c <= 6; c++) {
            if (grid[r][c] && car_dir[grid[r][c]] == -1) {
                if (grid[r + dr[0]][c + dc[0]] == grid[r][c]) {
                    car_dir[grid[r][c]] = 0;
                    if (grid[r + dr[0] * 2][c + dc[0] * 2] == grid[r][c]) {
                        car_len[grid[r][c]] = 3;
                    } else {
                        car_len[grid[r][c]] = 2;
                    }
                } else {
                    car_dir[grid[r][c]] = 2;
                    if (grid[r + dr[2] * 2][c + dc[2] * 2] == grid[r][c]) {
                        car_len[grid[r][c]] = 3;
                    } else {
                        car_len[grid[r][c]] = 2;
                    }
                }
            }
        }
    }
    int ans_step = -1;
    queue<tuple<grid_t, int>> que;
    set<grid_t> st;
    que.emplace(grid, 0);
    st.emplace(grid);
    while (!que.empty() && ans_step == -1) {
        auto [cur_grid, step] = que.front();
        que.pop();
        if (step + 1 + car_len[1] > 10)
            break;
        vector<bool> moved(11, false);
        for (int r = 1; r <= 6; r++) {
            for (int c = 1; c <= 6; c++) {
                int id = cur_grid[r][c];
                if (id && !moved[id]) {
                    moved[id] = true;
                    int d = car_dir[id];
                    if (!cur_grid[r + dr[d] * car_len[id]][c + dc[d] * car_len[id]]) {
                        grid_t nxt_grid = cur_grid;
                        swap(nxt_grid[r][c], nxt_grid[r + dr[d] * car_len[id]][c + dc[d] * car_len[id]]);
                        if (nxt_grid[3][6] == 1) {
                            ans_step = step + 1 + car_len[1];
                            break;
                        } else if (st.find(nxt_grid) == st.end()) {
                            que.emplace(nxt_grid, step + 1);
                            st.emplace(nxt_grid);
                        }
                    }
                    if (!cur_grid[r + dr[d + 1]][c + dc[d + 1]]) {
                        grid_t nxt_grid = cur_grid;
                        swap(nxt_grid[r + dr[d] * (car_len[id] - 1)][c + dc[d] * (car_len[id] - 1)], nxt_grid[r + dr[d + 1]][c + dc[d + 1]]);
                        if (nxt_grid[3][6] == 1) {
                            ans_step = step + 1 + car_len[1];
                            break;
                        } else if (st.find(nxt_grid) == st.end()) {
                            que.emplace(nxt_grid, step + 1);
                            st.emplace(nxt_grid);
                        }
                    }
                }
            }
        }
    }
    cout << ans_step << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}