#include <bits/stdc++.h>
using namespace std;
using Pos = pair<int, int>;

Pos operator+(const Pos& a, const Pos& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
const array<Pos, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
int main() {
    int k, n, m, ans;
    int grid[205][205];
    array<Pos, 105> k_pos;
    array<bool, 105> has_k;

    fill(has_k.begin(), has_k.end(), false);

    cin >> k >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2021) {
                has_k[0] = true;
                k_pos[0] = make_pair(i, j);
            } else if (grid[i][j] <= 100 && grid[i][j] >= 1) {
                has_k[grid[i][j]] = true;
                k_pos[grid[i][j]] = make_pair(i, j);
            }
        }
    }

    for (int i = 0; i <= k; i++)
        if (has_k[i] == false) {
            cout << "-1\n";
            return 0;
        }

    ans = 0;
    for (int target = 1; target <= k; target++) {
        bool found = false;
        queue<tuple<Pos, int>> tasks;
        bool exped[205][205] = {};
        tasks.push(make_tuple(k_pos[0], 0));
        while (!tasks.empty()) {
            auto [cur_pos, steps] = tasks.front();
            tasks.pop();

            int cur_id = grid[cur_pos.first][cur_pos.second];

            if (cur_id == -1 || exped[cur_pos.first][cur_pos.second]) continue;

            if (cur_id == target) {
                ans += steps;
                k_pos[0] = cur_pos;
                found = true;
                break;
            }

            exped[cur_pos.first][cur_pos.second] = true;

            for (auto dir : directions) {
                Pos nxt_pos = cur_pos + dir;
                if (nxt_pos.first < n && nxt_pos.first >= 0 && nxt_pos.second < m && nxt_pos.second >= 0)
                    tasks.push(make_tuple(nxt_pos, steps + 1));
            }
        }
        if (!found) {
            ans = -1;
            break;
        }
    }

    cout << ans << "\n";
}