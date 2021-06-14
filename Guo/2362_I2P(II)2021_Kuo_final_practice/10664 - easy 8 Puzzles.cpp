#include <bits/stdc++.h>
using namespace std;
using State = vector<int>;
set<State> _extend(State s);
bool _found(State s);
int main() {
    int T;
    cin >> T;

    while (T--) {
        State initState(9);
        set<State> explored;
        queue<tuple<State, int>> tasks;
        int ans = -1;

        for (int i = 0; i < 9; i++) {
            cin >> initState[i];
        }
        explored.insert(initState);

        tasks.push(make_tuple(initState, 1));

        if (_found(initState)) ans = 0;
        while (!tasks.empty() && ans == -1) {
            const auto [curState, curStep] = tasks.front();
            tasks.pop();

            set<State> nxtStates = _extend(curState);
            for (auto s : nxtStates) {
                if (explored.find(s) != explored.end()) continue;
                if (_found(s)) {
                    ans = curStep;
                    break;
                } else {
                    explored.insert(s);
                    if (curStep < 14)
                        tasks.push(make_tuple(s, curStep + 1));
                }
            }
        }

        if (ans != -1)
            cout << "You can solve it within " + to_string(ans) + " steps.\n";
        else
            cout << "You'd better skip this game.\n";
    }
}

set<State> _extend(State s) {
    static const vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int pos = 0;
    set<State> nextStates;
    for (int i = 0; i < 9; i++) {
        if (s[i] == 0) pos = i;
    }
    for (auto d : directions) {
        State _s = s;
        int x = pos % 3 + d[0], y = pos / 3 + d[1];
        if (x < 3 && x >= 0 && y < 3 && y >= 0) {
            swap(_s[pos], _s[y * 3 + x]);
            nextStates.insert(_s);
        }
    }
    return nextStates;
}
bool _found(State s) {
    static const State _s = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    return s == _s;
}