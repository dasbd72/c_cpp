#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(vector<string> N, string OP, vector<pair<int, int>> &pos, int p) {
    if (p == pos.size()) {
        if (stoi(N[0]) > 0 && stoi(N[1]) > 0 && stoi(N[2]) > 0) {
            if (OP == "+") {
                if (stoi(N[0]) + stoi(N[1]) == stoi(N[2])) {
                    cout << N[0] << " " << N[1] << " " << N[2] << "\n";
                    return true;
                }
            } else {
                if (stoi(N[0]) - stoi(N[1]) == stoi(N[2])) {
                    cout << N[0] << " " << N[1] << " " << N[2] << "\n";
                    return true;
                }
            }
        }
        return false;
    }
    for (int n = 9; n >= 0; n--) {
        N[pos[p].first][pos[p].second] = n + '0';
        if (dfs(N, OP, pos, p + 1))
            return true;
    }
    return false;
}
void solve() {
    string OP, EQ;
    vector<string> N(3);
    cin >> N[0] >> OP >> N[1] >> EQ >> N[2];
    vector<pair<int, int>> pos;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (int)N[i].size(); j++) {
            if (N[i][j] == 'X') {
                pos.emplace_back(i, j);
            }
        }
    }
    dfs(N, OP, pos, 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}