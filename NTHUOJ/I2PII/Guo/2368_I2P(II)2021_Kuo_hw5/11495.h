#include <iostream>
#include <list>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::set;
using std::vector;

// A state contains five components:
// The first two components denote the current numbers of
// missionaries and cannibals at the left bank of the river.
// The third and fourth components denote the current numbers
// of missionaries and cannibals at the right bank.
// The fifth component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing {
   private:
    vector<int> _npeople;     // how many missionaries and cannibals
                              // we use vector<int> as a tuple (int, int)
                              // the first integer indicate the number of missionaries
                              // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;

   public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np) : _npeople{np} {}
    // the starting point of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[4] to indicate the direction of move
    State Go(State s, int missionary, int cannibal);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4] == 1)
                        cout << " left\n";
                    else
                        cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};

#include <bits/stdc++.h>
using std::map;
using std::prev;
using std::queue;

void Crossing::solve() {
    queue<list<State>> tasks;
    map<State, list<State>> stateToSolutions;
    tasks.push(list<State>(1, {_npeople[0], _npeople[1], 0, 0, 1}));

    while (!tasks.empty()) {
        list<State> currPath, newPath;
        set<State> nextStates;
        State currState;
        currPath = tasks.front();
        tasks.pop();

        currState = *prev(currPath.end());
        _explored.insert(currState);

        nextStates = extend(currState);
        for (auto state : nextStates) {
            if (_explored.find(state) != _explored.end())
                continue;
            newPath = currPath;
            newPath.push_back(state);
            if (found(state)) {
                _solutions.insert(newPath);
            } else {
                tasks.push(newPath);
            }
        }
    }
}

set<State> Crossing::extend(State s) {
    set<State> nextStates;
    State nextState;
    for (int c = 0; c <= 2; c++) {
        for (int m = 0; m <= 2; m++) {
            if (c + m <= 2 && c + m >= 1) {
                nextState = Go(s, m, c);
                if (valid(nextState)) nextStates.insert(nextState);
            }
        }
    }
    return nextStates;
}

State Crossing::Go(State s, int missionary, int cannibal) {
    s[0] -= s[4] * missionary;
    s[1] -= s[4] * cannibal;
    s[2] += s[4] * missionary;
    s[3] += s[4] * cannibal;
    s[4] = -s[4];
    return s;
}

bool Crossing::valid(State s) {
    if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0) return false;
    return ((s[0] == 0 || s[0] >= s[1]) && (s[2] == 0 || s[2] >= s[3]));
}

bool Crossing::found(State s) {
    return (s[0] == 0 && s[1] == 0);
}
