#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, X;
    vector<int> vec;
    set<int> S;
    cin >> N >> X;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        vec.emplace_back(x);
        S.emplace(x);
    }

    for (int i = 0; i < N - 1; i++) {
        if (X - vec[i] != vec[i]) {
            if (S.find(X - vec[i]) != S.end()) {
                cout << i + 1 << " " << find(vec.begin(), vec.end(), X - vec[i]) - vec.begin() + 1 << "\n";
                return;
            }
        } else {
            auto it = find(vec.begin() + i + 1, vec.end(), X - vec[i]);
            if (it != vec.end()) {
                cout << i + 1 << " " << it - vec.begin() + 1 << "\n";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2