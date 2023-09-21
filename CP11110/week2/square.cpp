#include <bits/stdc++.h>
using namespace std;
int n, m;
int len[25];
int sumlen;
int avelen;
int side[5];
bool dfs(int idx) {
    if (side[1] == avelen && side[2] == avelen && side[3] == avelen) {
        return true;
    }
    if (idx == m) {
        return false;
    }
    for (int i = 1; i <= 4; i++) {
        if (side[i] + len[idx] > avelen)
            continue;
        side[i] += len[idx];
        if (dfs(idx + 1))
            return true;
        side[i] -= len[idx];
        if(side[i] == 0) return false;
    }
    return false;
}
void solve() {
    cin >> n;
    while (n--) {
        cin >> m;
        sumlen = 0;
        for (int i = 0; i < m; ++i) {
            cin >> len[i];
            sumlen += len[i];
        }
        sort(len, len + m, greater<int>());
        fill(side, side + 5, 0);
        avelen = sumlen / 4;
        bool availible = true;
        if (sumlen % 4 != 0)
            availible = false;
        if (availible)
            for (int i = 0; i < m; ++i)
                if (len[i] > avelen)
                    availible = false;
        if (availible)
            availible = dfs(0);

        if (availible)
            cout << "yes\n";
        else
            cout << "no\n";
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