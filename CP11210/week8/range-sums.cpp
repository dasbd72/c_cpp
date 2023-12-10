#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// go right along the edge means add
// go left along the edge means sub
// if 0 can reach n, it is Yes
void solve() {
    int n, q, l, r;
    cin >> n >> q;
    vector<vector<int> > tree(n + 1, vector<int>());
    while (q--) {
        cin >> l >> r;
        tree[l - 1].emplace_back(r);
        tree[r].emplace_back(l - 1);
    }

    queue<pair<int, int> > que;
    vector<int> record(n + 1, 0);
    que.emplace(0, -1);
    record[0] = 1;

    while (!que.empty() && !record[n]) {
        for (int len = (int)que.size(); len-- && !record[n];) {
            auto [u, parent] = que.front();
            que.pop();
            for (auto v : tree[u]) {
                if (v == parent)
                    continue;
                if (record[v])
                    continue;
                record[v] = 1;
                que.emplace(v, u);
            }
        }
    }

    if (record[n])
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
