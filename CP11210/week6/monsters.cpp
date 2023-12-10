#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class labyrinth {
    enum symbol : char {
        flo = '.',
        wal = '#',
        sta = 'A',
        mon = 'M',
    };
    const int dc[4] = {0, 0, -1, 1};
    const int dr[4] = {-1, 1, 0, 0};
    const char dsymbol[4] = {'U', 'D', 'L', 'R'};

    int h, w;
    vector<string> grid;

    string ans;
    vector<vector<int>> monster_dist;
    vector<vector<int>> drecord;
    tuple<int, int, int> end;

   public:
    labyrinth(int _h, int _w, vector<string> _grid) : h(_h), w(_w), grid(_grid), monster_dist(h, vector<int>(w, 4 * h * w)), drecord(h, vector<int>(w, 0)) {}

    void setup_monster_dist() {
        vector<vector<int>> record(h, vector<int>(w, 0));
        queue<tuple<int, int, int>> que;
        auto push = [&](int r, int c, int dist) {
            record[r][c] = 1;
            que.emplace(r, c, dist);
            monster_dist[r][c] = dist;
        };
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (grid[r][c] == mon) {
                    push(r, c, 0);
                }
            }
        }
        while (!que.empty()) {
            auto [pr, pc, pdist] = que.front();
            que.pop();
            for (int d = 0; d < 4; d++) {
                int r = pr + dr[d], c = pc + dc[d], dist = pdist + 1;
                if (r < 0 || r >= h || c < 0 || c >= w || record[r][c] || grid[r][c] == '#')
                    continue;
                push(r, c, dist);
            }
        }
    }
    bool find_path() {
        bool solved = false;
        vector<vector<int>> record(h, vector<int>(w, 0));
        queue<tuple<int, int, int>> que;
        auto push = [&](int r, int c, int dist) {
            record[r][c] = 1;
            que.emplace(r, c, dist);
            if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
                solved = true;
                end = make_tuple(r, c, dist);
            }
        };
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (grid[r][c] == sta) {
                    push(r, c, 0);
                }
            }
        }
        while (!que.empty() && !solved) {
            auto [pr, pc, pdist] = que.front();
            que.pop();
            for (int d = 0; d < 4; d++) {
                int r = pr + dr[d], c = pc + dc[d], dist = pdist + 1;
                if (r < 0 || r >= h || c < 0 || c >= w || record[r][c] || grid[r][c] == '#' || monster_dist[r][c] <= dist)
                    continue;
                drecord[r][c] = d;
                push(r, c, dist);
            }
        }

        return solved;
    }
    void solve() {
        setup_monster_dist();

        if (find_path()) {
            // Rebuild path
            string seq;
            auto [r, c, dist] = end;
            while (dist--) {
                if (r < 0 || r >= h || c < 0 || c >= w) {
                    break;
                }
                int d = drecord[r][c];
                if (d < 0 || d >= 4)
                    break;
                seq = dsymbol[d] + seq;
                r -= dr[d];
                c -= dc[d];
            }
            cout << "YES\n";
            cout << seq.size() << "\n";
            cout << seq << "\n";
        } else {
            cout << "NO\n";
        }
    }
};
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int r = 0; r < h; r++) {
        cin >> grid[r];
    }
    labyrinth laby(h, w, grid);
    laby.solve();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
