#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    while (L + 1 < R) {
        Ty Mid = L + (R - L) / 2;
        if (check(Mid))
            L = Mid;
        else
            R = Mid;
    }
    return {L, R};
}

void solve() {
    // Cart run A m/s
    // Speed up to B m/s
    // Cost C units/s
    // Refill D units/s
    // initial M units
    // length S meters
    // limit T sec to win
    ll A, B, C, D, M, S, T;
    cin >> A >> B >> C >> D >> M >> S >> T;

    auto check_total_time = [&](ll sec) {
        for (ll st = 0;; st++) {
            ll rt = st * C < M ? 0 : ceil(double(st * C - M) / D);
            if (st + rt > sec)
                return true;
            if (st * B + (sec - st - rt) * A >= S) {
                // cout << st << " " << rt << "\n";
                return false;
            }
        }
    };

    if (!check_total_time(T)) {
        cout << "Yes\n";
        // Search time
        auto [l, r] = binarySearch((ll)0, T + 1, check_total_time);
        cout << r << "\n";
    } else {
        cout << "No\n";
        // Search distance
        ll max_dist = 0;
        for (ll st = 0;; st++) {
            ll rt = st * C < M ? 0 : ceil(double(st * C - M) / D);
            if (st + rt > T)
                break;
            max_dist = max(max_dist, st * B + (T - st - rt) * A);
        }
        cout << max_dist << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}