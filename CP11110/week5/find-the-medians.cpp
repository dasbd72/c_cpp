#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N;
    priority_queue<int, vector<int>, greater<int>> rheap;
    priority_queue<int, vector<int>, less<int>> lheap;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (lheap.empty() || x <= lheap.top()) {
            lheap.emplace(x);
            if (lheap.size() > rheap.size() + 1) {
                rheap.emplace(lheap.top());
                lheap.pop();
            }
        } else {
            rheap.emplace(x);
            if (rheap.size() > lheap.size()) {
                lheap.emplace(rheap.top());
                rheap.pop();
            }
        }
        cout << lheap.top() << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}