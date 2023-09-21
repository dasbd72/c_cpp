#include <bits/stdc++.h>
using namespace std;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
void bfs(vector<string>& grid, int N, int M, int r, int c, int label, vector<vector<int>>& record) {
    queue<tuple<int, int>> que;
    que.emplace(r, c);
    record[r][c] = label;
    while (!que.empty()) {
        int cur_r = get<0>(que.front());
        int cur_c = get<1>(que.front());
        que.pop();
        for (int d = 0; d < 4; d++) {
            int nxt_r = cur_r + dr[d];
            int nxt_c = cur_c + dc[d];
            if (nxt_r >= 0 && nxt_r < N && nxt_c >= 0 && nxt_c < M && grid[nxt_r][nxt_c] == '.' && !record[nxt_r][nxt_c]) {
                record[nxt_r][nxt_c] = label;
                que.emplace(nxt_r, nxt_c);
            }
        }
    }
}
void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    vector<vector<int>> record(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    int ans = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == '.' && !record[r][c]) {
                bfs(grid, N, M, r, c, ans + 1, record);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}