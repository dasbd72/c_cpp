#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.emplace_back(a, i + 1);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rem = x - arr[i].first - arr[j].first;
            if (rem < 0)
                continue;
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                int tmp = arr[l].first + arr[r].first;
                if (tmp == rem) {
                    cout << arr[i].second << " " << arr[j].second << " " << arr[l].second << " " << arr[r].second << "\n";
                    return;
                }
                if (tmp < rem) {
                    l++;
                } else {
                    r--;
                }
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
