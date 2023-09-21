#include <bits/stdc++.h>
using namespace std;
const int MASK = (1 << 10) - 2;
int row[9];
int col[9];
int sub[9];
string s;
int lowbit(int x) {
    return x & (~x + 1);
}
int lg(int x) {
    switch (x) {
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
        default:
            exit(1);
            return -1;
    }
}
bool dfs(int idx) {
    if (idx == 81) {
        cout << s << "\n";
        return true;
    }
    int avai = MASK & ~(row[idx / 9] | col[idx % 9] | sub[int(idx / 27) * 3 + (idx % 9) / 3]);
    if (s[idx] == '.') {
        for (int num; avai; avai ^= num) {
            num = lowbit(avai);
            row[idx / 9] ^= num;
            col[idx % 9] ^= num;
            sub[int(idx / 27) * 3 + (idx % 9) / 3] ^= num;
            s[idx] = '0' + lg(num);
            if (dfs(idx + 1))
                return true;
            row[idx / 9] ^= num;
            col[idx % 9] ^= num;
            sub[int(idx / 27) * 3 + (idx % 9) / 3] ^= num;
            s[idx] = '.';
        }
    } else {
        if (dfs(idx + 1))
            return true;
    }
    return false;
}
void solve() {
    while (cin >> s) {
        if (s == "end")
            break;
        fill(row, row + 9, 0);
        fill(col, col + 9, 0);
        fill(sub, sub + 9, 0);
        bool no_sol = false;
        for (int idx = 0; idx < 81; idx++) {
            if (s[idx] != '.') {
                int avai = MASK & ~(row[idx / 9] | col[idx % 9] | sub[int(idx / 27) * 3 + (idx % 9) / 3]);
                int num = (1 << (s[idx] - '0'));
                if (num & avai) {
                    row[idx / 9] ^= num;
                    col[idx % 9] ^= num;
                    sub[int(idx / 27) * 3 + (idx % 9) / 3] ^= num;
                } else {
                    no_sol = true;
                    break;
                }
            }
        }
        if (no_sol || !dfs(0))
            cout << "No solution.\n";
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