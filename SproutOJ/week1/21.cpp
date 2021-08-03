#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, T, X;
    list<int> place;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) place.push_back(i);
    while (M--) {
        cin >> T >> X;
        if (T == 0) {
            place.remove(X);
        } else {
            auto it = find(place.begin(), place.end(), X);
            if (it != place.begin()) swap(*it, *prev(it));
        }
    }
    for (auto it = place.begin(); it != place.end(); it++) {
        cout << *it << (next(it) == place.end() ? "\n" : " ");
    }
    return 0;
}