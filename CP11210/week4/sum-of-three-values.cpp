#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                int sum = a[i].first + a[j].first + a[m].first;
                if (sum < x)
                    l = m + 1;
                else
                    r = m;
            }
            if (l < n && a[i].first + a[j].first + a[l].first == x) {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[l].second + 1 << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}