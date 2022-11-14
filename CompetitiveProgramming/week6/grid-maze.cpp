#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
char dd[] = {'D', 'R', 'U', 'L'};
void solve() {
    int N, M;
    cin >> N >> M;
    char grid[N + 2][M + 2];
    pair<int, int> A_pos, B_pos;
    for (int r = 0; r < N + 2; r++) {
        for (int c = 0; c < M + 2; c++) {
            grid[r][c] = '#';
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'A')
                A_pos = make_pair(r, c);
            if (grid[r][c] == 'B')
                B_pos = make_pair(r, c);
        }
    }
    int ans = -1;
    queue<tuple<int, int, int>> que;
    bool record[N + 2][M + 2];
    int path[N + 2][M + 2];
    for (int r = 0; r < N + 2; r++) {
        for (int c = 0; c < M + 2; c++) {
            record[r][c] = false;
            path[r][c] = -1;
        }
    }
    que.emplace(A_pos.first, A_pos.second, 0);
    record[A_pos.first][A_pos.second] = true;
    while (!que.empty() && ans == -1) {
        auto [cur_r, cur_c, cur_step] = que.front();
        que.pop();
        for (int d = 0; d < 4; d++) {
            int nxt_r = cur_r + dr[d];
            int nxt_c = cur_c + dc[d];
            
            if (grid[nxt_r][nxt_c] == 'B') {
                ans = cur_step + 1;
                path[nxt_r][nxt_c] = d;
                break;
            } else if (grid[nxt_r][nxt_c] == '.' && !record[nxt_r][nxt_c]) {
                record[nxt_r][nxt_c] = true;
                path[nxt_r][nxt_c] = d;
                que.emplace(nxt_r, nxt_c, cur_step + 1);
            }
        }
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