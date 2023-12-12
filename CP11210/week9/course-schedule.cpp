#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > adj_t;
void solve() {
    int n, m, a, b;
    cin >> n >> m;
    adj_t adj(n);
    vector<int> in_degree(n, 0);
    while (m--) {
        cin >> a >> b;
        a--, b--;
        adj[a].emplace_back(b);
        in_degree[b]++;
    }

    // BFS
    vector<int> result;
    queue<int> que;
    vector<int> rec(n, 0);
    auto push = [&](int u) {
        que.emplace(u);
        rec[u] = 1;
        result.emplace_back(u);
    };
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                push(v);
        }
    }
    if ((int)result.size() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto u : result) {
        cout << u + 1 << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
