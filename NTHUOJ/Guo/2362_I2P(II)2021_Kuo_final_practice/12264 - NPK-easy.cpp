#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string op;
    deque<queue<int>> line;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "ENQUEUE") {
            int x;
            bool flag = true;
            cin >> x;
            for (auto it = line.begin(); it != line.end(); it++) {
                if (it->front() % 3 == x % 3) {
                    it->push(x);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                queue<int> que;
                que.push(x);
                line.push_back(que);
            }
        } else if (op == "DEQUEUE") {
            if (!line.empty()) {
                cout << line.begin()->front() << endl;
                line.begin()->pop();
                if (line.begin()->empty()) line.pop_front();
            }
        }
    }
}