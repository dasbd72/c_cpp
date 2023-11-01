#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void test_case() {
    int n;
    cin >> n;
    vector<int> arr(n);
    bool ans = 1;
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (maximum > arr[i])
            ans = false;
        maximum = max(maximum, arr[i]);

        // cout << i + 1 << ", " << pow(2, ceil(log2(i + 1))) << "\n";
        if (i == pow(2, ceil(log2(i + 1))) - 1)
            maximum = 0;
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}
void solve() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
