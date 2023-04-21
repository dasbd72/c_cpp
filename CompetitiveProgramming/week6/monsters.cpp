#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int dd[] = {'D', 'R', 'U', 'L'};
void solve() {
    int N, M;
    cin >> N >> M;
    char grid[N + 2][M + 2];
    pair<int, int> A_pos;
    vector<pair<int, int>> Ms_pos;
    for (int r = 0; r <= N + 1; r++) {
        for (int c = 0; c <= M + 1; c++) {
            grid[r][c] = '#';
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'A') {
                A_pos = make_pair(r, c);
            } else if (grid[r][c] == 'M') {
                Ms_pos.emplace_back(r, c);
            }
        }
    }
    int ans = -1, step = 1;
    pair<int, int> B_pos;
    queue<tuple<int, int, char>> que;
    vector<vector<int>> record(N + 2, vector<int>(M + 2, 0));
    int path[N + 2][M + 2];
    for (auto M_pos : Ms_pos) {
        que.emplace(M_pos.first, M_pos.second, 'M');
        record[M_pos.first][M_pos.second] = 0;
    }
    que.emplace(A_pos.first, A_pos.second, 'A');
    record[A_pos.first][A_pos.second] = 0;
    while (!que.empty() && ans == -1) {
        cout << step << "\n";
        for (int q = que.size(); q-- && ans == -1;) {
            auto [r, c, ply] = que.front();
            que.pop();
            for (int d = 0; d < 4 && ans == -1; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (record[nr][nc] != step && grid[nr][nc] == '.') {
                    if (ply == 'A')
                        path[nr][nc] = d;
                    record[nr][nc] = step;
                    if (ply == 'A' && (nr == 1 || nr == N || nc == 1 || nc == M)) {
                        ans = step;
                        B_pos = make_pair(nr, nc);
                    } else {
                        que.emplace(nr, nc, ply);
                    }
                }
            }
        }
        step++;
    }
    if (ans == -1) {
        cout << "NO\n";
    } else {
        string ans_seq;
        int r = B_pos.first, c = B_pos.second;
        while (grid[r][c] != 'A') {
            int d = path[r][c];
            ans_seq += dd[d];
            r -= dr[d];
            c -= dc[d];
        }
        cout << "YES\n";
        cout << ans << "\n";
        for (auto rit = ans_seq.rbegin(); rit != ans_seq.rend(); rit++) {
            cout << *rit;
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}