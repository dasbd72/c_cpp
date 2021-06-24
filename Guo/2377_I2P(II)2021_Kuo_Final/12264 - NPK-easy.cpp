#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, id;
    string op;

    cin >> N;
    queue<int> country[3];
    queue<int> line;
    while (N--) {
        cin >> op;
        if (op == "ENQUEUE") {
            cin >> id;
            if (country[id % 3].empty()) {
                country[id % 3].push(id);
                line.push(id % 3);
            } else {
                country[id % 3].push(id);
            }
        } else if (op == "DEQUEUE") {
            if (line.empty()) continue;
            cout << country[line.front()].front() << "\n";
            country[line.front()].pop();
            if (country[line.front()].empty()) line.pop();
        }
    }
}