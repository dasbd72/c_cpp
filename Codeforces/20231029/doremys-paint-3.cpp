#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void test_case() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int a = 0, b = 0, failed = 0;
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (a == 0 || a == arr[i])
            a = arr[i], cnt_a++;
        else if (b == 0 || b == arr[i])
            b = arr[i], cnt_b++;
        else
            failed = 1;
    }
    if (!failed && (cnt_b == 0 || (abs(cnt_a - cnt_b) <= 1)))
        cout << "Yes\n";
    else
        cout << "No\n";
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
