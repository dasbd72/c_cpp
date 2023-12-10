#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<string, 6> cube_t;

void solve() {
    while (true) {
        cube_t cube;
        int dot_cnt = 0;
        for (int i = 0; i < 6; i++) {
            cin >> cube[i];
            for (auto c : cube[i])
                if (c == '.')
                    dot_cnt++;
        }
        // end of input
        if (dot_cnt == 48)
            break;

        array<char, 6> colors;  // colors of faces of answer, FDLRUB
        const cube_t corners = {
            "..AB....",
            "..CD....",
            "ACCDDBBA",
            "EOOGGFFE",
            "..OG....",
            "..EF....",
        };
        const cube_t faces = {
            "..EE....",
            "..EE....",
            "CCAADDFF",
            "CCAADDFF",
            "..BB....",
            "..BB....",
        };
        colors[0] = cube[3][2];
        colors[1] = cube[4][2];
        colors[2] = cube[3][1];
        {
            array<set<char>, 8> threes;
            for (int r = 0; r < 6; r++)
                for (int c = 0; c < 8; c++)
                    if (corners[r][c] != 'O' && corners[r][c] != '.')
                        threes[corners[r][c] - 'A'].emplace(cube[r][c]);
            for (int i = 0; i < 7; i++) {
                if (threes[i].find(colors[0]) != threes[i].end() && threes[i].find(colors[1]) != threes[i].end() && threes[i].find(colors[2]) == threes[i].end()) {
                    threes[i].erase(colors[0]);
                    threes[i].erase(colors[1]);
                    colors[3] = *threes[i].begin();
                } else if (threes[i].find(colors[0]) != threes[i].end() && threes[i].find(colors[1]) == threes[i].end() && threes[i].find(colors[2]) != threes[i].end()) {
                    threes[i].erase(colors[0]);
                    threes[i].erase(colors[2]);
                    colors[4] = *threes[i].begin();
                } else if (threes[i].find(colors[0]) == threes[i].end() && threes[i].find(colors[1]) != threes[i].end() && threes[i].find(colors[2]) != threes[i].end()) {
                    threes[i].erase(colors[1]);
                    threes[i].erase(colors[2]);
                    colors[5] = *threes[i].begin();
                }
            }
        }

        auto get_dist = [&](cube_t& st) {
            int cnt = 0;
            for (int r = 0; r < 6; r++) {
                for (int c = 0; c < 8; c++) {
                    if (faces[r][c] != '.')
                        if (st[r][c] != colors[faces[r][c] - 'A'])
                            cnt++;
                }
            }
            return cnt;
        };

        auto comp = [&](pair<cube_t, string>& lhs, pair<cube_t, string>& rhs) {
            int lcnt = get_dist(lhs.first);
            int rcnt = get_dist(rhs.first);
            if (lcnt != rcnt)
                return lcnt < rcnt;
            if (lhs.second.length() != rhs.second.length())
                return lhs.second.length() > rhs.second.length();
            return false;
        };

        priority_queue<pair<cube_t, string>, vector<pair<cube_t, string>>, decltype(comp)> que(comp);
        set<cube_t> record;
        bool done = false;
        string ans;

        auto rotate_face = [](cube_t& st, int r, int c, int d) {
            if (!d) {
                // counter clockwise
                swap(st[r][c], st[r + 1][c]);
                swap(st[r][c], st[r][c + 1]);
                swap(st[r][c + 1], st[r + 1][c + 1]);
            } else {
                // clockwise
                swap(st[r][c], st[r + 1][c]);
                swap(st[r + 1][c], st[r + 1][c + 1]);
                swap(st[r + 1][c + 1], st[r][c + 1]);
            }
        };

        auto turn = [&](cube_t& st, int axis) {
            if (axis == 0) {
                // X
                rotate_face(st, 2, 4, 0);
                swap(st[2][3], st[4][3]);  // FD
                swap(st[3][3], st[5][3]);
                swap(st[0][3], st[2][3]);  // UF
                swap(st[1][3], st[3][3]);
                swap(st[3][6], st[0][3]);  // BU
                swap(st[2][6], st[1][3]);
            } else if (axis == 1) {
                // Y
                rotate_face(st, 0, 2, 0);
                swap(st[2][2], st[2][0]);
                swap(st[2][3], st[2][1]);
                swap(st[2][0], st[2][6]);
                swap(st[2][1], st[2][7]);
                swap(st[2][6], st[2][4]);
                swap(st[2][7], st[2][5]);
            } else {
                // Z
                rotate_face(st, 2, 2, 0);
                swap(st[4][2], st[2][1]);
                swap(st[4][3], st[3][1]);
                swap(st[2][1], st[1][3]);
                swap(st[3][1], st[1][2]);
                swap(st[1][3], st[3][4]);
                swap(st[1][2], st[2][4]);
            }
        };

        auto check = [](cube_t& st) {
            auto subcheck = [&](int r, int c) {
                return st[r][c] == st[r][c + 1] && st[r][c] == st[r + 1][c] && st[r][c] == st[r + 1][c + 1];
            };
            return subcheck(0, 2) && subcheck(2, 0) && subcheck(2, 2) && subcheck(2, 4) && subcheck(2, 6) && subcheck(4, 2);
        };

        auto push_state = [&](cube_t& st, string path) {
            if (check(st)) {
                done = true;
                ans = path;
                return;
            }
            if (record.find(st) == record.end()) {
                record.emplace(st);
                que.emplace(st, path);
            }
        };

        auto print = [](cube_t& st) {
            cout << "\n";
            for (auto str : st) {
                cout << str << "\n";
            }
        };

        push_state(cube, "");

        for (; !que.empty() && !done;) {
            for (int len = que.size(); len-- && !done;) {
                auto [curr_state, curr_path] = que.top();
                que.pop();
                for (int d = 0; d < 3 && !done; d++) {
                    auto next_state = curr_state;
                    auto next_path = curr_path;
                    turn(next_state, d);
                    next_path.push_back(d + 'X');
                    push_state(next_state, next_path);
                }
            }
        }

        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
