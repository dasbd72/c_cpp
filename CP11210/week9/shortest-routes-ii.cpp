#include <bits/stdc++.h>
using namespace std;

#define MAX_DIST 1e18

typedef long long ll;

class graph {
    int n;
    vector<vector<ll> > dist;

   public:
    graph(int _n) : n(_n), dist(n, vector<ll>(n, MAX_DIST)) {
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
    }

    void push(int u, int v, ll w) {
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = dist[u][v];
    }

    void floyd() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    ll query(int u, int v) {
        if (dist[u][v] == MAX_DIST)
            return -1;
        return dist[u][v];
    }
};
void solve() {
    int n, m, q, u, v;
    ll w;
    cin >> n >> m >> q;
    graph g(n);
    while (m--) {
        cin >> u >> v >> w;
        u--, v--;
        g.push(u, v, w);
    }
    g.floyd();
    while (q--) {
        cin >> u >> v;
        u--, v--;
        cout << g.query(u, v) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
