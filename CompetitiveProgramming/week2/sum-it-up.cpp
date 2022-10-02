#include <bits/stdc++.h>
using namespace std;
int t, n;
int x[15];
bool answered;

void dfs(int sel, int sum, int idx, int ignored) {
    if (sum == t) {
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (sel & (1 << i)) {
                cout << (first ? "" : "+") << x[i];
                first = false;
            }
        }
        cout << "\n";
        answered = true;
        return;
    }
    if (idx == n || sum > t) {
        return;
    }

    if (ignored != x[idx]) {
        dfs(sel | (1 << idx), sum + x[idx], idx + 1, ignored);
    }
    dfs(sel, sum, idx + 1, x[idx]);
}
void solve() {
    while (cin >> t >> n) {
        if (t == 0 && n == 0)
            break;
        answered = false;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n, greater<int>());
        cout << "Sums of " << t << ":\n";
        dfs(0, 0, 0, 0);
        if (!answered) {
            cout << "NONE\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2