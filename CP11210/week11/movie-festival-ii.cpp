#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin(), movies.end());
    multiset<int, greater<int>> s;
    for (int i = 0; i < k; i++) {
        s.emplace(1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(movies[i].second);
        if (it == s.end())
            continue;
        ans++;
        s.erase(it);
        s.insert(movies[i].first);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
