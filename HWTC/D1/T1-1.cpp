#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long K, T;
    vector<long long> Ks;
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> K;
        Ks.emplace_back(K);
    }
    sort(Ks.begin(), Ks.end());

    long long lo = 0, hi = 1e18, ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sum = 0;

        for (auto k : Ks) {
            sum += (mid / k);
            if (sum >= T)
                break;
        }

        if (sum >= T) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-1.cpp ; ./a.out <T1-1.in