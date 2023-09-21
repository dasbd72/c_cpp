#include <bits/stdc++.h>
using namespace std;
int p0[] = {0, 1, 3, 4, 6, 7, 0, 1, 2, 3, 4, 5};
int p1[] = {1, 2, 4, 5, 7, 8, 3, 4, 5, 6, 7, 8};
int power[10];
bool check(int &grid) {
    for (int i = 0; i < 9; i++) {
        if ((grid / power[i]) % 9 != i)
            return false;
    }
    return true;
}
void move(int& grid, int a, int b) {
    int tmp1 = (grid / power[a]) % 9;
    int tmp2 = (grid / power[b]) % 9;
    grid += (tmp2 - tmp1) * power[a];
    grid += (tmp1 - tmp2) * power[b];
}
void solve() {
    power[0] = 1;
    for (int i = 1; i < 9; i++) {
        power[i] = 9 * power[i - 1];
    }
    int grid = 0;
    for (int i = 0, x; i < 9; i++) {
        cin >> x;
        grid += (x - 1) * power[i];
    }
    int ans = -1;
    set<int> st;
    queue<tuple<int, int>> que;
    if (check(grid)) {
        ans = 0;
    } else {
        que.emplace(grid, 0);
        st.emplace(grid);
    }
    while (!que.empty() && ans == -1) {
        auto [cur_grid, cur_step] = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            auto nxt_grid = cur_grid;
            move(nxt_grid, p0[i], p1[i]);
            if (st.find(nxt_grid) == st.end()) {
                if (check(nxt_grid)) {
                    ans = cur_step + 1;
                    break;
                } else {
                    st.emplace(nxt_grid);
                    que.emplace(nxt_grid, cur_step + 1);
                }
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