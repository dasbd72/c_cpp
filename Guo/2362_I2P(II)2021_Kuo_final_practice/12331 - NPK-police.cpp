#include <bits/stdc++.h>
using namespace std;
using Group = queue<long long>;
using ListOfGroups = list<Group>;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string op;
    bool isPoliceWatching = false;
    array<list<ListOfGroups::iterator>, 3> country;
    ListOfGroups line;

    while (cin >> op) {
        if (op == "ENQUEUE") {
            long long x;
            cin >> x;
            if (!country[x % 3].empty() && (!isPoliceWatching || *prev(country[x % 3].end()) == prev(line.end()))) {
                auto it = *prev(country[x % 3].end());
                it->push(x);
            } else {
                Group que;
                que.push(x);
                line.push_back(que);
                country[x % 3].push_back(prev(line.end()));
            }
        } else if (op == "DEQUEUE") {
            if (line.empty()) continue;

            auto it = line.begin();
            long long x = it->front();
            it->pop();
            cout << x << "\n";

            if (it->empty()) {
                line.pop_front();
                country[x % 3].pop_front();
            }
        } else if (op == "POLICEWATCHING") {
            isPoliceWatching = true;
        } else if (op == "DONUTSTIME") {
            isPoliceWatching = false;
        }
    }
}