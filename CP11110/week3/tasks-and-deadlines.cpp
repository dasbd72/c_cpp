#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
void solve() {
    int n;
    cin >> n;
    vector<pll> input;
    for(int i = 0; i < n; i++) {
        long long a, d;
        cin >> a >> d;
        input.emplace_back(a, d);
    }
    sort(input.begin(), input.end(), less<pll>());
    long long reward = 0, finish_time = 0;
    for(int i = 0; i < n; i++) {
        finish_time += input[i].first;
        reward += input[i].second - finish_time;
    }
    cout << reward << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2