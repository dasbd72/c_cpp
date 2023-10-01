#include <bits/stdc++.h>
using namespace std;

int low_bit_log(int x) {
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
            return -1;
    }
}
int low_bit(int x) {
    return low_bit_log(x & -x);
}
int recursive(int n, int m, int mask, int QL, int QR, int SL, int SR, int M) {
    if (n == 0 && m == 0)
        return 1;

    int ret = 0;
    if (n) {
        int ava = ~(QL | M | QR) & mask;
        while (ava) {
            int col = low_bit(ava);
            ava &= ~(1 << col) & mask;
            ret += recursive(n - 1, m, mask, ((QL | (1 << col)) << 1) & mask, (QR | (1 << col)) >> 1, ((SL | (1 << col)) << 1) & mask, (SR | (1 << col)) >> 1, M | (1 << col));
        }
    }
    if (m) {
        int ava = ~(SL | M | SR) & mask;
        while (ava) {
            int col = low_bit(ava);
            ava &= ~(1 << col) & mask;
            ret += recursive(n, m - 1, mask, ((QL | (1 << col)) << 1) & mask, (QR | (1 << col)) >> 1, (SL << 1) & mask, SR >> 1, M | (1 << col));
        }
    }
    return ret;
}
int get_ways(int n, int m) {
    int mask = (1 << (n + m)) - 1;
    return recursive(n, m, mask, 0, 0, 0, 0, 0);
}
void test_case() {
    int n, m;
    cin >> n >> m;
    cout << get_ways(n, m) << "\n";
}
void solve() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}