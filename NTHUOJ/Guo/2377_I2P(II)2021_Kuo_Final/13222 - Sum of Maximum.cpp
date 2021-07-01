#include <bits/stdc++.h>
using namespace std;
array<int, 2000005> saved;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> saved[i];
        ans += saved[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            ans += saved[j] = max(saved[j], saved[j - 1]);
        }
    }
    cout << ans << "\n";
}