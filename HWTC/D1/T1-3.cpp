#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long P, tot = 0, ans = 1e18;
    vector<long long> weights;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        weights.emplace_back(P);
        tot += P;
    }

    for (int i = 0; i < (1 << N); i++) {
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += weights[j];
                ans = min(ans, abs(sum * 2 - tot));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-3.cpp ; ./a.out <T1-3.in