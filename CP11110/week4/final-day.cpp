#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P, Pmax;
    for(int i = 0; i < N; i++) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        P.emplace_back(p1 + p2 + p3);
        Pmax.emplace_back(p1 + p2 + p3 + 300);
    }
    sort(P.begin(), P.end(), greater<int>());
    for(int i = 0; i < N; i++) {
        if(Pmax[i] >= P[K - 1])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}