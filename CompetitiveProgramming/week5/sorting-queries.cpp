#include <bits/stdc++.h>
using namespace std;
void solve() {
    int Q, T, X;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> heap;
    queue<int> que;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X;
            que.emplace(X);
        } else if (T == 2) {
            if (!heap.empty()) {
                cout << heap.top() << "\n";
                heap.pop();
            } else {
                cout << que.front() << "\n";
                que.pop();
            }
        } else {
            while (!que.empty()) {
                heap.emplace(que.front());
                que.pop();
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}