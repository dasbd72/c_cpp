#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5001][5001] = {};
vector<ll> arr(1, 0);
vector<ll> prefixsum(1, 0);

ll run(int l, int r) {
    if (dp[l][r])
        return dp[l][r];
    ll result;
    if (l == r) {
        result = arr[l];
    } else {
        result = prefixsum[r] - prefixsum[l - 1] - min(run(l + 1, r), run(l, r - 1));
    }
    return dp[l][r] = result;
}
void solve() {
    int N, X;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X;
        arr.emplace_back(X);
        prefixsum.emplace_back(prefixsum[i - 1] + X);
    }
    cout << run(1, N) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T3-3.cpp ; ./a.out <T3-3.in