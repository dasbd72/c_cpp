#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<array<int, 6>, 6> brd;

int check(brd &board) {
    int red_head = 0;
    while (board[2][red_head] != 1) red_head++;
    for (int i = 5;; i--) {
        if (board[2][i] != 0 && board[2][i] != 1)
            return 0;
        if (board[2][i] == 1)
            return 6 - red_head;
    }
    return 0;
}
bool move(brd &board, int car, int dir) {
    bool found = false;
    int car_r, car_c, delta;

    if (dir == 0) {
        delta = 1;
        for (int r = 0; r < 6 && !found; r++) {
            for (int c = 0; c < 6 && !found; c++) {
                if (board[r][c] == car) {
                    found = true;
                    car_r = r, car_c = c;
                }
            }
        }
    } else {
        delta = -1;
        for (int r = 5; r >= 0 && !found; r--) {
            for (int c = 5; c >= 0 && !found; c--) {
                if (board[r][c] == car) {
                    found = true;
                    car_r = r, car_c = c;
                }
            }
        }
    }

    bool ret = false;
    if (car_r + delta >= 0 && car_r + delta < 6 && board[car_r + delta][car_c] == car) {
        // up down
        int i = car_r + delta;
        while (i >= 0 && i < 6 && board[i][car_c] == car) i += delta;
        if (i >= 0 && i < 6 && board[i][car_c] == 0) {
            ret = true;
            swap(board[car_r][car_c], board[i][car_c]);
        }
    } else {
        // left right
        int i = car_c + delta;
        while (i >= 0 && i < 6 && board[car_r][i] == car) i += delta;
        if (i >= 0 && i < 6 && board[car_r][i] == 0) {
            ret = true;
            swap(board[car_r][car_c], board[car_r][i]);
        }
    }
    return ret;
}
void solve() {
    brd board;
    int cnt = 0;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            cin >> board[r][c];
            cnt = max(cnt, board[r][c]);
        }
    }

    queue<brd> que;
    set<brd> st;
    bool solved = false;
    int ans = 100;
    que.push(board);
    st.insert(board);
    for (int steps = 1; steps <= 10 && !solved; steps++) {
        for (int len = que.size(); len-- && !solved;) {
            brd curr_board = que.front();
            que.pop();
            for (int i = 1; i <= cnt && !solved; i++) {
                for (int d = 0; d <= 1 && !solved; d++) {
                    brd next_board = curr_board;

                    if (move(next_board, i, d)) {
                        // Successfully moved
                        int ret = check(next_board);
                        if (ret) {
                            // Solved
                            ans = min(ans, ret + steps);
                            solved = true;
                        } else if (st.find(next_board) == st.end()) {
                            que.emplace(next_board);
                            st.insert(next_board);
                        }
                    }
                }
            }
        }
    }

    if (ans > 10) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
