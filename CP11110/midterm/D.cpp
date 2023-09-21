#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    list<int> lst;
    lst.emplace_back(0);
    auto it = lst.begin();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            lst.insert(it, i + 1);
            it = prev(it);
        } else {
            lst.insert(next(it), i + 1);
            it = next(it);
        }
    }
    for (auto x : lst) {
        cout << x << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}