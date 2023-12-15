#include <bits/stdc++.h>
using namespace std;

#define MOD ((int)(1e9 + 7))
typedef long long ll;
typedef vector<vector<ll> > mat_t;

mat_t mult(mat_t& a, mat_t& b) {
    int n = a.size();
    mat_t ret(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j] % MOD)) % MOD;
            }
        }
    }
    return ret;
}
mat_t pow(mat_t x, int y) {
    int n = x.size();
    mat_t ret(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) ret[i][i] = 1;
    while (y > 0) {
        if (y & 1) {
            ret = mult(ret, x);
        }
        x = mult(x, x);
        y >>= 1;
    }
    return ret;
}
void solve() {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    mat_t mat(n, vector<ll>(n, 0));
    while (m--) {
        cin >> a >> b;
        a--, b--;
        mat[a][b] ++;
    }
    mat = pow(mat, k);
    cout << mat[0][n - 1] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
