#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long p[25];
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    long long ans = 0x7fffffffffffffff;
    for (int i = 0; i < (1 << n); i++) {
        long long group = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                group += p[j];
        }
        ans = min(ans, abs(2 * group - sum));
    }
    cout << ans << "\n";
    return 0;
}