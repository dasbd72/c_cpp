#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    set<pair<int, int> > rarr;
    vector<int> larr;

    while (n--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r;
            cin >> l >> r;
            rarr.emplace(r, (int)larr.size());
            larr.emplace_back(l);
        } else {
            int x;
            cin >> x;

            if (larr.empty()) {
                cout << "1\n";
                continue;
            }

            auto it = rarr.lower_bound(make_pair(x, 0));

            if (it != rarr.end() && it->first >= x && larr[it->second] <= x) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}