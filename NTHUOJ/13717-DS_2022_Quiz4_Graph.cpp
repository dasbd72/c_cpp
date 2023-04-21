#include <iostream>
using namespace std;
typedef unsigned long long ll;
const ll maxlength = 100000000;
int N, E;
ll M;
ll dist[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> E;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = maxlength;
        }
    }
    for (int i = 0; i < E; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = 0;
    int idx;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i != j && dist[i][j] <= M) {
                cnt++;
            }
        }
        if (cnt >= ans) {
            ans = cnt;
            idx = i;
        }
    }

    cout << idx << "\n";
    for (int j = 0; j < N; j++) {
        if (dist[idx][j] <= M && idx != j) {
            cout << j << " ";
        }
    }
    cout << "\n";
}