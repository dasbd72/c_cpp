#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll N, X;
    cin >> N >> X;
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i].first + A[j].first >= X)
                continue;
            ll target = X - A[i].first - A[j].first;
            int l = j + 1, r = N - 1;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (A[m].first < target) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (A[l].first == target) {
                cout << A[i].second + 1 << " " << A[j].second + 1 << " " << A[l].second + 1 << "\n";
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
}