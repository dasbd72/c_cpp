#include <bits/stdc++.h>
using namespace std;
void solve() {
    string X;
    stack<char> stk;
    cin >> X;
    for (auto c : X) {
        if(c == 'T' && !stk.empty() && stk.top() == 'S') {
            stk.pop();
        } else {
            stk.emplace(c);
        }
    }
    cout << stk.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}