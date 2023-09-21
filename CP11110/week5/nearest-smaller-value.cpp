#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N;
    cin >> N;
    stack<pair<int, int>> stk;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        while (!stk.empty() && stk.top().first >= x) {
            stk.pop();
        }

        if (stk.empty()) {
            cout << "0 ";
        } else {
            cout << stk.top().second << " ";
        }

        stk.emplace(x, i);
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}