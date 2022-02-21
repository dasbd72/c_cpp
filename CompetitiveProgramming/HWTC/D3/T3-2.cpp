#include <bits/stdc++.h>
using namespace std;
vector<int> coins;
int dp[1000001];
int run(int target) {
    if (dp[target])
        return dp[target];
    int cost = numeric_limits<int>::max();
    int result;
    for (auto C : coins) {
        if (target == C) {
            cost = 1;
            break;
        }
        if (target < C)
            break;
        result = run(target - C);
        if (result != numeric_limits<int>::max())
            cost = min(cost, result + 1);
    }
    return dp[target] = cost;
}
void solve() {
    int N, X, C;
    int result;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> C;
        coins.emplace_back(C);
    }
    sort(coins.begin(), coins.end());
    result = run(X);
    if (result == numeric_limits<int>::max())
        result = -1;
    cout << result << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T3-2.cpp ; ./a.out <T3-2.in