#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) {
    return x & (~x + 1);
}
const int MASK = (1 << 8) - 1;
int reserved[8];        // columns reserved in rows
int ans;
void dfs(int r, int L, int M, int R) {
    if (M == MASK) {
        ans++;
        return;
    }
    int avai = MASK & ~(reserved[r] | L | M | R);
    for (int num; avai; avai ^= num) {
        num = lowbit(avai);
        dfs(r + 1, (L | num) << 1, M | num, (R | num) >> 1);
    }
}
void solve() {
    string s[8];
    for (int r = 0; r < 8; r++) {
        cin >> s[r];
    }
    for (int r = 0; r < 8; r++) {
        reserved[r] = 0;
        for (int c = 0; c < 8; c++) {
            if (s[r][c] == '*') {
                reserved[r] |= (1 << c);
            }
        }
    }
    ans = 0;
    dfs(0, 0, 0, 0);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2