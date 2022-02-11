#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, K;
    multiset<int> towers;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        auto it = towers.upper_bound(K);
        if (towers.empty() || it == towers.end()) {
            towers.emplace(K);
        } else {
            towers.erase(it);
            towers.emplace(K);
        }
    }

    cout << towers.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T3-1.cpp ; ./a.out <T3-1.in