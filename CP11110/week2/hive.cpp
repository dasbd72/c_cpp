#include <bits/stdc++.h>
using namespace std;
const int dr[2][6] = {{-1, -1, 0, 1, 1, 0}, {-1, -1, 0, 1, 1, 0}};
const int dc[2][6] = {{0, 1, 1, 1, 0, -1}, {-1, 0, 1, 0, -1, -1}};
int N, R, C;
int room_r[4], room_c[4];
int weight[12][7];
int pipe[12][7];
int min_sum;
void dfs(int isnec, int nec_r, int nec_c, int hon_r, int hon_c, int sum, int pre_d) {
    int nr, nc;
    int sd, ed;
    if(isnec) {
        if(pre_d == -1) {
            for(int d = 0; d < 6; ++d) {
                nr = nec_r + dr[nec_r % 2][d];
                nc = nec_c + dc[nec_r % 2][d];
                if(nr == room_r[1] && nc == room_c[1]) {
                    dfs(0, nr, nc, hon_r, hon_c, sum, -1);
                } else if(!pipe[nr][nc]) {
                    pipe[nr][nc] = 2;
                    dfs(isnec, nr, nc, hon_r, hon_c, sum + weight[nr][nc], d);
                    pipe[nr][nc] = 0;
                }
            }
        } else{
            sd = (pre_d + 5) % 6;
            ed = (pre_d + 8) % 6;
            for(int d = sd; d != ed; d = (d + 1) % 6) {
                nr = nec_r + dr[nec_r % 2][d];
                nc = nec_c + dc[nec_r % 2][d];
                if(nr == room_r[1] && nc == room_c[1]) {
                    dfs(0, nr, nc, hon_r, hon_c, sum, -1);
                } else if(!pipe[nr][nc]) {
                    pipe[nr][nc] = 2;
                    dfs(isnec, nr, nc, hon_r, hon_c, sum + weight[nr][nc], d);
                    pipe[nr][nc] = 0;
                }
            }
        }
    } else {
        if(pre_d == -1) {
            for(int d = 0; d < 6; ++d) {
                nr = hon_r + dr[hon_r % 2][d];
                nc = hon_c + dc[hon_r % 2][d];
                if(nr == room_r[3] && nc == room_c[3]) {
                    min_sum = min(min_sum, sum);
                } else if(!pipe[nr][nc]) {
                    pipe[nr][nc] = 3;
                    dfs(isnec, nec_r, nec_c, nr, nc, sum + weight[nr][nc], d);
                    pipe[nr][nc] = 0;
                }
            }
        } else{
            sd = (pre_d + 5) % 6;
            ed = (pre_d + 8) % 6;
            for(int d = sd; d != ed; d = (d + 1) % 6) {
                nr = hon_r + dr[hon_r % 2][d];
                nc = hon_c + dc[hon_r % 2][d];
                if(nr == room_r[3] && nc == room_c[3]) {
                    min_sum = min(min_sum, sum);
                } else if(!pipe[nr][nc]) {
                    pipe[nr][nc] = 3;
                    dfs(isnec, nec_r, nec_c, nr, nc, sum + weight[nr][nc], d);
                    pipe[nr][nc] = 0;
                }
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
        min_sum = 0x7fffffff;
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            pipe[room_r[i]][room_c[i]] = (i < 2 ? 2 : 3);
            sum += weight[room_r[i]][room_c[i]];
        }
        dfs(1, room_r[0], room_c[0], room_r[2], room_c[2], sum, -1);
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