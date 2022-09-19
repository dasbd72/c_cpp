#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        long long ans = 0;
        cin >> n >> k;
        priority_queue<long long> a[105];
        for(int i = 0, ki = 0, x; i < n; i++, ki = (ki + 1) % k) {
            cin >> x;
            a[ki].push(x);
        }
        for(int ki = 0; ki < k; ki++) {
            ans += a[ki].top();
        }
        cout << ans << "\n";
    }
    return 0;
}