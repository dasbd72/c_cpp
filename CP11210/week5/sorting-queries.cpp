#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int q, c, x;
    cin >> q;
    deque<int> dq;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> x;
            dq.push_back(x);
        } else if (c == 2) {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else {
            for(auto val : dq) {
                pq.push(val);
            }
            dq.clear();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
