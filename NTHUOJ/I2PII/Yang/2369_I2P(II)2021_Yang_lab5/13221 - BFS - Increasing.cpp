#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, sy, sx, ey, ex, Ans = -1;
    cin >> N >> M;
    vector<vector<int>> Grid(N + 2, vector<int>(M + 2, 0));
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> Grid[y][x];
        }
    }
    cin >> sy >> sx >> ey >> ex;
    queue<tuple<int, int, int>> tasks;  // y, x, steps
    set<tuple<int, int>> states;        // y, x
    tasks.push(make_tuple(sy, sx, 0));
    while (!tasks.empty()) {
        auto [y, x, steps] = tasks.front();
        tasks.pop();
        if (y == ey && x == ex) {
            Ans = steps;
            break;
        }
        if (states.find(make_tuple(y, x)) != states.end())
            continue;
        states.insert(make_tuple(y, x));
        if (Grid[y][x] <= Grid[y - 1][x])
            tasks.push(make_tuple(y - 1, x, steps + 1));
        if (Grid[y][x] <= Grid[y][x + 1])
            tasks.push(make_tuple(y, x + 1, steps + 1));
        if (Grid[y][x] <= Grid[y + 1][x])
            tasks.push(make_tuple(y + 1, x, steps + 1));
        if (Grid[y][x] <= Grid[y][x - 1])
            tasks.push(make_tuple(y, x - 1, steps + 1));
    }
    cout << Ans << endl;
}