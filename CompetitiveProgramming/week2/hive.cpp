#include <bits/stdc++.h>
using namespace std;
const int dr[2][6] = {{-1, -1, 0, 1, 1, 0}, {-1, 0, 1, 1, 0, -1}};
const int dc[2][6] = {{0, 1, 1, 1, 0, -1}, {0, 1, 0, -1, -1, -1}};
int N, R, C;
int room_r[4], room_c[4];
int weight[12][7];
int pipe[12][7];
int min_sum;
bool reachable(int s_r, int s_c, int e_r, int e_c) {
    int grid[12][7];
    for(int i = 0; i < 12; i++) {
        copy(pipe[i], pipe[i] + 7, grid[i]);
    }
    queue<pair<int, int>> que;
    que.emplace(s_r, s_c);
    while(!que.empty()) {
        int r, c, nr, nc;
        r = que.front().first;
        c = que.front().second;
        que.pop();
        for(int d = 0; d < 6; ++d) {
            nr = r + dr[r % 2][d];
            nc = c + dc[r % 2][d];
            if(nr == e_r && nc == e_c)
                return true;
            if(!grid[nr][nc]) {
                grid[nr][nc] = 2;
                que.emplace(nr, nc);
            }
        }
    }
    return false;
}
void dfs(int nec_r, int nec_c, int hon_r, int hon_c, int sum) {
    int nr, nc;
    if(sum > min_sum)
        return;
    // for (int r = 0; r <= R + 1; r++) {
    //     for (int c = 0; c <= C + 1; c++) {
    //         cout << pipe[r][c] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    if(nec_r != room_r[1] || nec_c != room_c[1]) {
        for(int d = 0; d < 6; ++d) {
            nr = nec_r + dr[nec_r % 2][d];
            nc = nec_c + dc[nec_r % 2][d];
            if(nr == room_r[1] && nc == room_c[1]) {
                if(reachable(hon_r, hon_c, room_r[3], room_c[3]))
                dfs(nr, nc, hon_r, hon_c, sum);
            } else if(!pipe[nr][nc]) {
                pipe[nr][nc] = 2;
                if(reachable(hon_r, hon_c, room_r[3], room_c[3]))
                dfs(nr, nc, hon_r, hon_c, sum + weight[nr][nc]);
                pipe[nr][nc] = 0;
            }
        }
    } else {
        for(int d = 0; d < 6; ++d) {
            nr = hon_r + dr[hon_r % 2][d];
            nc = hon_c + dc[hon_r % 2][d];
            if(nr == room_r[3] && nc == room_c[3]) {
                min_sum = min(min_sum, sum);
            } else if(!pipe[nr][nc]) {
                pipe[nr][nc] = 3;
                dfs(nec_r, nec_c, nr, nc, sum + weight[nr][nc]);
                pipe[nr][nc] = 0;
            }
        }
    }
}
void solve() {
    cin >> N;
    while (N--) {
        cin >> R >> C;
        for (int i = 0; i < 4; i++) {
            cin >> room_r[i] >> room_c[i];
        }
        for (int r = 0; r <= R + 1; r++) {
            fill(pipe[r], pipe[r] + 7, 1);
        }
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                cin >> weight[r][c];
                pipe[r][c] = 0;
            }
        }
        // Print test
        // for (int r = 0; r <= R + 1; r++) {
        //     for (int c = 0; c <= C + 1; c++) {
        //         cout << pipe[r][c] << " ";
        //     }
        //     cout << "\n";
        // }
        min_sum = 0x7fffffff;
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            pipe[room_r[i]][room_c[i]] = (i < 2 ? 2 : 3);
            sum += weight[room_r[i]][room_c[i]];
        }
        dfs(room_r[0], room_c[0], room_r[2], room_c[2], sum);
        if(min_sum == 0x7fffffff) 
            min_sum = -1;
        cout << min_sum << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2