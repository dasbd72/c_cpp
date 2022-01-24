#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, V;
    while (cin >> N >> M) {
        vector<vector<int>> pos(1000001);
        for (int i = 1, x; i <= N; i++) {
            cin >> x;
            pos[x].push_back(i);
        }
        while (M--) {
            cin >> K >> V;
            if (K <= pos[V].size())
                cout << pos[V][K - 1] << "\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-6.cpp ; ./a.out <H2-6.in