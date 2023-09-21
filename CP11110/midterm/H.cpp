#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lowbit(ll x) {
    return x & (~x + 1);
}
int getVal(vector<int> &parts, ll choice) {
}
bool dfs(int nsticks, vector<int> &parts, ll chosen, int istick, vector<int> sum, int target) {
    if (istick == nsticks) {
    }
}
void solve() {
    int N;
    while (cin >> N) {
        if (N == 0)
            break;
        vector<int> parts(N);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> parts[i];
            sum += parts[i];
        }
        for (int l = 1; l <= N; l++) {
            int nsticks = N / l;
            if (sum % nsticks != 0)
                continue;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}