#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    vector<ll> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    queue<ll> que;
    array<bool, 2000005> record;
    fill(record.begin(), record.end(), false);
    int steps = 1;
    bool done = false;

    auto push = [&](ll val) {
        if (val == x)
            done = true;
        else if (!record[val]) {
            record[val] = true;
            que.emplace(val);
        }
    };

    push(1);

    for (; !que.empty(); steps++) {
        for (int len = que.size(); len-- && !done;) {
            auto st = que.front();
            que.pop();
            for (int i = 0; i < k && !done; i++) {
                push(((st * arr[i] - 1) % n) + 1);
            }
        }
        if (done)
            break;
    }

    if (done)
        cout << steps << "\n";
    else
        cout << "I LOVE TSING HUA\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}