#include <bits/stdc++.h>
using namespace std;

void combinations(int n, int m, int idx, vector<int>& vec, vector<int>& choice) {
    if (idx > m) {
        for (int i = 1; i <= m; i++) {
            cout << vec[choice[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = choice[idx - 1] + 1; i < n; i++) {
        choice[idx] = i;
        combinations(n, m, idx + 1, vec, choice);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        vec.emplace_back(x);
    }
    vector<int> choice(m + 1, 0);
    choice[0] = -1;
    combinations(n, m, 1, vec, choice);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}