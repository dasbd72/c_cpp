#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(const vector<ll>& vec, const int& K, const ll val) {
    int k = 1;
    ll sum = 0;
    for (auto x : vec) {
        if (sum + x <= val) {
            sum = sum + x;
        } else if(x <= val) {
            sum = x;
            k++;
        } else {
            return false;
        }
        if (k > K)
            return false;
    }
    return true;
}
ll binarySearch(const vector<ll>& vec, const int& K, const ll lval, const ll rval) {
    if (lval == rval) {
        return lval;
    }
    ll mid = lval + (rval - lval) / 2;
    if (check(vec, K, mid)) {
        return binarySearch(vec, K, lval, mid);
    } else {
        return binarySearch(vec, K, mid + 1, rval);
    }
}
void solve() {
    int N, K;
    vector<ll> vec;
    cin >> N >> K;
    vector<ll> prefixSum;
    ll preSum = 0;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        vec.emplace_back(x);
        preSum += x;
        prefixSum.emplace_back(preSum);
    }
    cout << binarySearch(vec, K, 1, prefixSum[N - 1]) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}