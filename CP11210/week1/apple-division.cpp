#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long sum = 0;
    vector<long long> w;
    cin >> n;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        w.emplace_back(x);
        sum += x;
    }
    long long diff = sum;
    for(int i = 0; i < (1 << n); i++) {
        long long partial = 0;
        for(int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                partial += w[j];
            }
        }
        diff = min(diff, abs(sum - 2 * partial));
    }
    cout << diff << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}