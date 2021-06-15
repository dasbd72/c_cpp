#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0, x; i < K; i++) {
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist + 100005, -1);

    for (int x : diamondTowns) {
        queue<pair<int, int>> tasks;

        tasks.push(make_pair(x, 0));
        while (!tasks.empty()) {
            auto [curIdx, curDist] = tasks.front();
            tasks.pop();
            if (Dist[curIdx] != -1 && curDist >= Dist[curIdx]) continue;
            if (Dist[curIdx] == -1 || curDist < Dist[curIdx]) Dist[curIdx] = curDist;

            for (auto nxt : G[curIdx]) {
                tasks.push(make_pair(nxt, curDist + 1));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}