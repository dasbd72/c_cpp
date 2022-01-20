#include <bits/stdc++.h>
using namespace std;
using Grid = array<array<int, 505>, 505>;
Grid edge, oneedge, path;
int main() {
    int n, q;
    int k, m;
    int u, v, x;
    cin >> n >> q;
    // initialize
    for (int i = 0; i < n; i++) {
        fill(path[i].begin(), path[i].end(), INT_MAX);
        path[i][i] = oneedge[i][i] = 0;
    }

    // get input
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> x;
        edge[u][v] = path[u][v] = 1;
        edge[v][u] = path[v][u] = 1;
        oneedge[u][v] = oneedge[v][u] = x;
    }

    // set
    for (int i = 0; i < n; i++) {
        queue<tuple<int, int, int>> tasks;
        set<int> explored;

        tasks.push(make_tuple(i, 0, 0));
        while (!tasks.empty()) {
            auto [cur_id, steps, ones] = tasks.front();
            tasks.pop();
            if (explored.find(cur_id) != explored.end()) {
                continue;
            }
            explored.insert(cur_id);
            if (path[i][cur_id] > steps) {
                path[i][cur_id] = steps;
                oneedge[i][cur_id] = ones;
            }
            for (int j = 0; j < n; j++) {
                if (edge[cur_id][j]) tasks.push(make_tuple(j, steps + 1, ones + oneedge[cur_id][j]));
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << path[i][j] << "," << oneedge[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while (q--) {
        int cnt = 0;
        cin >> k >> m;
        for (int i = 0, prev, curr; i < k; i++) {
            cin >> curr;
            if (i != 0) {
                cnt += oneedge[prev][curr];
            }
            prev = curr;
        }
        cout << (cnt >= m ? "YES" : "NO") << "\n";
    }
}