#include <iostream>
#include <list>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::set;
using std::vector;

// A state contains seven components:
// The first three components denote the current numbers of
// wolves, goats and cabbages at the left bank of the river.
// The fourth to sixth components denote the current numbers
// of wolves, goats and cabbages at the right bank.
// The seventh component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing {
   private:
    vector<int> _items;       // wolves, goats and cabbages
                              // we use vector<int> as a tuple (int, int, int)
                              // the first integer indicates the number of wolves
                              // the second integer indicates the number of goats
                              // the third integer indicates the number of cabbages.
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;

   public:
    // specify the numbers of wolves, goats and cabbages
    Crossing(vector<int> np) : _items{np} {}
    // the starting point of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[6] to indicate the direction of move
    State Go(State s, int wolf, int goat, int cabbage);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ", " << s[2] << ")";
                    cout << "(" << s[3] << ", " << s[4] << ", " << s[5] << ")";
                    if (s[6] == 1)
                        cout << " left\n";
                    else
                        cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};
/*--------------------------Start----------------------*/
// (!farmer && (#W > #G || #G > #C))
#include <queue>
using std::prev;
using std::queue;
void Crossing::solve() {
    queue<list<State>> tasks;
    tasks.push(list<State>(1, {_items[0], _items[1], _items[2], 0, 0, 0, 1}));
    while (!tasks.empty()) {
        list<State> currPath, nextPath;
        set<State> nextStates;
        State currState;
        currPath = tasks.front();
        tasks.pop();

        currState = *prev(currPath.end());
        nextStates = extend(currState);
        for (auto nextState : nextStates) {
            bool flag = false;
            for (auto review : currPath) {
                if (review == nextState) flag = true;
            }
            if (flag) continue;
            nextPath = currPath;
            nextPath.push_back(nextState);
            if (found(nextState)) {
                _solutions.insert(nextPath);
            } else {
                tasks.push(nextPath);
            }
        }
    }
}
set<State> Crossing::extend(State s) {
    set<State> nextStates;
    State nextState;
    for (int i = 1; i <= 8; i <<= 1) {
        nextState = Go(s, i == 8, i == 4, i == 2);
        if (valid(nextState)) nextStates.insert(nextState);
    }

    return nextStates;
}
State Crossing::Go(State s, int wolf, int goat, int cabbage) {
    s[0] -= s[6] * wolf;
    s[1] -= s[6] * goat;
    s[2] -= s[6] * cabbage;
    s[3] += s[6] * wolf;
    s[4] += s[6] * goat;
    s[5] += s[6] * cabbage;
    s[6] *= -1;
    return s;
}
bool Crossing::valid(State s) {
    return (s[0] >= 0 && s[1] >= 0 && s[2] >= 0 && s[3] >= 0 && s[4] >= 0 && s[5] >= 0 && ((s[6] == 1 && (s[3] <= s[4] || s[4] == 0) && (s[4] <= s[5] || s[5] == 0)) || (s[6] == -1 && (s[0] <= s[1] || s[1] == 0) && (s[1] <= s[2] || s[2] == 0))));
}
bool Crossing::found(State s) {
    return (s[0] == 0 && s[1] == 0 && s[2] == 0);
}
