#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > rq;
    priority_queue<int, vector<int>, less<int> > lq;
    lq.push(0);
    rq.push(1e9);

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (lq.size() > rq.size()) {
            if (lq.top() > x) {
                rq.push(lq.top());
                lq.pop();
                lq.push(x);
            } else {
                rq.push(x);
            }
        } else {
            if (rq.top() < x) {
                lq.push(rq.top());
                rq.pop();
                rq.push(x);
            } else {
                lq.push(x);
            }
        }

        cout << lq.top() << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}