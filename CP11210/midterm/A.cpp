#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());

    ll sum = 0, i = 0;
    while (sum < k && i < n) {
        sum += arr[i];
        i++;
    }
    if (sum >= k)
        cout << i << "\n";
    else
        cout << "-1\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}