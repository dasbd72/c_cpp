#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<pair<int, ll> > > adj_t;
class graph {
    int n;
    adj_t adj;
    vector<ll> dist;

   public:
    graph(int _n, adj_t _adj) : n(_n), adj(_adj), dist(n, 0x7fffffffffffffff) {
    }
    vector<ll> single_source_shortest_path() {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int>> > pq;
        vector<int> record(n, 0);
        dist[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (record[u])
                continue;
            record[u] = 1;
            for (auto [v, w] : adj[u]) {
                ll alt = d + w;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
};
void solve() {
    int n, m, a, b;
    ll c;
    cin >> n >> m;
    adj_t adj(n);
    while (m--) {
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
    }

    graph g(n, adj);
    auto dist = g.single_source_shortest_path();
    for (auto d : dist) {
        cout << d << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
