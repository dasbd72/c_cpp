#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        vector<set<int>> child(1005);
        int ans = 0, R;
        for (int i = 0, a, b; i < N; i++) {
            cin >> a >> b;
            child[a].insert(b);
            child[a].insert(0);
            child[b].insert(0);
        }
        cin >> R;
        for (auto s : child) {
            if (s.size() == 1) ans++;
        }
        cout << ans << endl;
    }
}