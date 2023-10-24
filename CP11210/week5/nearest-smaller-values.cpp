#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    stack<pair<int, int> > stk;
    for (int i = 0; i < n; i++) {
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
        stk.emplace(x, i + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
