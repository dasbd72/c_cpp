#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    string S;
    cin >> S;
    stack<char> stk;
    for (auto c : S) {
        if (!stk.empty() && c == 'T' && stk.top() == 'S') {
            stk.pop();
        } else {
            stk.push(c);
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
