#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> factorization(int n) {
    vector<int> ans;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans.emplace_back(i);
        }
    }
    if (n != 1)
        ans.emplace_back(n);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> num_divisors(1e6 + 5, 0);
    vector<vector<int> > divisors(n);
    for (int i = 0; i < n; i++) {
        divisors[i] = factorization(arr[i]);

        for (int s = 1; s < (1 << divisors[i].size()); s++) {
            int mult = 1;
            for (int j = 0; j < divisors[i].size(); j++) {
                if (!(s & (1 << j)))
                    continue;
                mult *= divisors[i][j];
            }
            num_divisors[mult]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ans += n - 1;
            continue;
        }
        ans += n;
        for (int s = 1; s < (1 << divisors[i].size()); s++) {
            int cnt = 0;
            int mult = 1;
            for (int j = 0; j < divisors[i].size(); j++) {
                if (!(s & (1 << j)))
                    continue;
                cnt++;
                mult *= divisors[i][j];
            }
            ans -= (cnt % 2 ? 1 : -1) * num_divisors[mult];
        }
    }

    cout << ans / 2 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
