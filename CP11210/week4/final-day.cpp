#include <bits/stdc++.h>
using namespace std;

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

void solve_() {
    // O(Nlog(N))
    int N, K;
    cin >> N >> K;

    vector<pair<int, int> > P(N);
    for (int i = 0; i < N; i++) {
        P[i].first = 0;
        P[i].second = i;
        for (int j = 0, x; j < 3; j++) {
            cin >> x;
            P[i].first += x;
        }
    }
    vector<pair<int, int> > copy_P(P);
    sort(copy_P.begin(), copy_P.end(), greater<pair<int, int> >());

    // Larger than or equal K th
    int thres = copy_P[K - 1].first;

    for (int i = 0; i < N; i++) {
        if (P[i].first + 300 >= thres)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

void solve() {
    // O(N)
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        P[i] = 0;
        for (int j = 0, x; j < 3; j++) {
            cin >> x;
            P[i] += x;
        }
    }

    auto calc = [&](int pt) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (P[i] >= pt)
                cnt++;
        }
        return cnt;
    };

    auto check = [&](int pt) {
        return calc(pt) >= K;
    };

    // Larger than or equal K th
    auto [l, r] = binarySearch(0, 1201, check);
    int thres = l;

    for (int i = 0; i < N; i++) {
        if (P[i] + 300 >= thres)
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