#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
void bfs(int N, int M, int r, int c, vector<string> &grid, vector<vector<bool>> &record) {
    queue<tuple<int, int>> que;
    que.emplace(r, c);
    while (!que.empty()) {
        auto [cur_r, cur_c] = que.front();
        que.pop();
        for (int d = 0; d < 4; d++) {
            int nxt_r = cur_r + dr[d];
            int nxt_c = cur_c + dc[d];
            if (grid[nxt_r][nxt_c] == '.' && !record[nxt_r][nxt_c]) {
                record[nxt_r][nxt_c] = true;
                que.emplace(nxt_r, nxt_c);
            }
        }
    }
}
void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N + 2, string(M + 2, '#'));
    for (int r = 1; r <= N; r++) {
        string inp;
        cin >> inp;
        grid[r] = string("#") + inp + string("#");
    }
    int ans = 0;
    vector<vector<bool>> record(N + 2, vector<bool>(M + 2, false));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] == '.' && !record[r][c]) {
                ans++;
                bfs(N, M, r, c, grid, record);
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}