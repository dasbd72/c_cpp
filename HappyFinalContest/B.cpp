#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, M, Q, K;
    cin >> N >> M >> Q;
    vector<tuple<int, int>> occupied;
    vector<tuple<int, int>> storage(M + 1, make_tuple(-1, -1));
    int max_storage = 0;

    for (int i = 0, l, r; i < N; i++) {
        cin >> l >> r;
        occupied.emplace_back(l, r);
    }
    occupied.emplace_back(0, 0);
    occupied.emplace_back(M + 1, M + 1);
    sort(occupied.begin(), occupied.end(), greater<tuple<int, int>>());

    for (size_t i = 0; i < occupied.size() - 1; i++) {
        int size = get<0>(occupied[i]) - get<1>(occupied[i + 1]) - 1;
        if (size > max_storage) {
            for (int j = max_storage + 1; j <= size; j++) {
                storage[j] = make_tuple(get<0>(occupied[i]) - j, get<0>(occupied[i]) - 1);
            }
            max_storage = size;
        }
    }

    while (Q--) {
        cin >> K;
        cout << get<0>(storage[K]) << " " << get<1>(storage[K]) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 B.cpp ; ./a.out <B.in