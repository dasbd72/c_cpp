#include <bits/stdc++.h>
using namespace std;
array<int, 1000000> group;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, X;
    string OP;
    for (int k = 1;; k++) {
        if (!(cin >> N)) break;

        group.fill(0);
        array<deque<int>, 1005> member;
        deque<pair<bool, int>> line;
        for (int i = 1; i <= N; i++) {
            cin >> K;
            for (int j = 0, x; j < K; j++) {
                cin >> x;
                group[x] = i;
            }
        }
        cout << "Line #" << k << "\n";
        while (cin >> OP) {
            if (OP == "ENQUEUE") {
                cin >> X;
                if (group[X] != 0) {
                    if (member[group[X]].empty()) {
                        line.push_back(make_pair(true, group[X]));
                    }
                    member[group[X]].push_back(X);
                } else {
                    line.push_back(make_pair(false, X));
                }
            } else if (OP == "DEQUEUE") {
                auto tmp = line.front();
                if (tmp.first) {
                    cout << member[tmp.second].front() << "\n";
                    member[tmp.second].pop_front();
                    if (member[tmp.second].empty()) line.pop_front();
                } else {
                    cout << tmp.second << "\n";
                    line.pop_front();
                }
            } else if (OP == "STOP") {
                break;
            }
        }
    }

    return 0;
}