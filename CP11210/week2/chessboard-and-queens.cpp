#include <bits/stdc++.h>
using namespace std;

int lowbit_log(int x) {
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
        default:
            return -1;
    }
}
int lowbit(int x) {
    return lowbit_log(x & -x);
}
int recursive(const array<int, 8>& rows, int idx, int L, int M, int R) {
    if (idx == 8)
        return 1;

    int ava = ~(rows[idx] | L | M | R) & ((1 << 8) - 1);

    int ret = 0;
    while (ava) {
        int pos = lowbit(ava);
        ret += recursive(rows, idx + 1, ((L | (1 << pos)) << 1) & ((1 << 8) - 1), M | (1 << pos), (R | (1 << pos)) >> 1);
        ava &= ~(1 << pos);
    }
    return ret;
}
int get_ways(const array<int, 8>& rows) {
    return recursive(rows, 0, 0, 0, 0);
}
void solve() {
    array<int, 8> rows;
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        int row = 0;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') {
                row |= (1 << j);
            }
        }
        rows[i] = row;
    }

    cout << get_ways(rows) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}