#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii padd(pii a, pii b) {
    return pii(a.first + b.first, a.second + b.second);
}
void solve() {
    long long k, n, m, x;
    cin >> k >> n >> m;
    queue<long long> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.push(x);
    }
    long long diff = 0, n_diff;
    long long d_a = 1, d_b = -1;
    long long t_prev = 1, t_curr;
    long long purple = 0;
    int condition;
    while (!a.empty() || !b.empty()) {
        if (!a.empty() && (b.empty() || (!b.empty() && a.front() < b.front()))) {
            t_curr = a.front();
            a.pop();
            condition = 1;
        } else if (!b.empty() && (a.empty() || (!a.empty() && a.front() > b.front()))) {
            t_curr = b.front();
            b.pop();
            condition = 2;
        } else {
            t_curr = a.front();
            a.pop();
            b.pop();
            condition = 3;
        }

        // cout << t_curr << ":\n";
        n_diff = diff + (d_a - d_b) * (t_curr - t_prev);
        // cout << n_diff << "\n";
        if ((diff > 0 && n_diff < 0) || (diff < 0 && n_diff > 0)) {
            purple++;
        } else if (diff == 0 && d_a == d_b) {
            purple += t_curr - t_prev;
        } else if (n_diff == 0) {
            purple++;
        }

        if (condition & 1)
            d_a = -d_a;
        if (condition & 2)
            d_b = -d_b;
        t_prev = t_curr;
        diff = n_diff;
    }
    t_curr = k + 1;
    n_diff = diff + (d_a - d_b) * (t_curr - t_prev);
    if ((diff > 0 && n_diff < 0) || (diff < 0 && n_diff > 0)) {
        purple++;
    } else if (diff == 0 && d_a == d_b) {
        purple += t_curr - t_prev;
    } else if (n_diff == 0) {
        purple++;
    }
    cout << k - purple << " " << k - purple << " " << purple << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2