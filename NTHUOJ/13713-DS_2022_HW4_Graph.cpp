#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 10000000;
int N, E, S, F, K;
vector<pair<int, int>> edge[1005];
ll dist[1005];
void solve() {
    cin >> N >> E;
    cin >> S >> F >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v, w);
    }
    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
    }
    queue<pair<int, int>> que;
    que.emplace(S, 0);
    dist[S] = 0;
    for (int n = 0; n <= K && !que.empty(); n++) {
        for (int k = que.size(); k--;) {
            auto cur = que.front();
            que.pop();
            for (auto nxt : edge[cur.first]) {
                if (dist[nxt.first] > nxt.second + cur.second) {
                    dist[nxt.first] = nxt.second + cur.second;
                    if (nxt.first != F && nxt.first != S) {
                        que.emplace(nxt.first, nxt.second + cur.second);
                    }
                }
            }
        }
    }

    cout << dist[F] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}