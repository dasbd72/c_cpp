#include <bits/stdc++.h>
using namespace std;

template <class FuncTy>
pair<double, double> ternarySearch(double L, double R, FuncTy func, double eps = 1e-6) {
    while (L + eps < R) {
        double LM = L + (R - L) / 3;
        double RM = R - (R - L) / 3;
        if (func(LM) > func(RM))
            L = LM;
        else
            R = RM;
    }
    return {L, R};
}

void solve() {
    int N, C;
    cin >> N >> C;
    vector<double> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    auto func = [&](double p) {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (p - X[i]) * (p - X[i]) + (C - Y[i]) * (C - Y[i]);
        }
        return sum;
    };

    auto [l, r] = ternarySearch(-1e5, 1e5, func, 1e-9);
    cout << setprecision(17) << func(l) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}