#include <bits/stdc++.h>
using namespace std;
int MASK;
int board_size;
int ans;

int lowbit(int x) {
    return x & (~x + 1);
}
int lg(int x) {
    switch (x) {
        case 1:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 8:
            return 3;
        case 16:
            return 4;
        case 32:
            return 5;
        case 64:
            return 6;
        case 128:
            return 7;
        case 256:
            return 8;
        case 512:
            return 9;
        case 1024:
            return 10;
        case 2048:
            return 11;
        default:
            exit(1);
            return -1;
    }
}
void dfs(int r, int m, int n, int L, int M, int R, int Lx, int Rx) {
    if (r == board_size) {
        if (m == 0 && n == 0) {
            ++ans;
        }
        return;
    }
    int avai;
    if (m) {
        avai = MASK & ~(L | M | R | Lx | Rx);
        for (int bt; avai; avai ^= bt) {
            bt = lowbit(avai);
            dfs(r + 1, m - 1, n, (L | bt) << 1, M | bt, (R | bt) >> 1, Lx << 1, Rx >> 1);
        }
    }
    if (n) {
        avai = MASK & ~(L | M | R);
        for (int bt; avai; avai ^= bt) {
            bt = lowbit(avai);
            dfs(r + 1, m, n - 1, L << 1, M | bt, R >> 1, (Lx | bt) << 1, (Rx | bt) >> 1);
        }
    }
}
void solve() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        board_size = m + n;
        MASK = (1 << board_size) - 1;
        ans = 0;
        dfs(0, m, n, 0, 0, 0, 0, 0);
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2