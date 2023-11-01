#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    deque<pair<int, int> > deq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < k) {
            if (deq.empty() || arr[i] >= deq.back().first)
                deq.emplace_back(arr[i], i);
        }
    }
    cout << deq.back().first << " ";

    for (int i = k; i < n + k - 1; i++) {
        if (deq.front().second <= i - k)
            deq.pop_front();

        if (deq.empty()) {
            for (int j = i - k + 1; j <= i; j++) {
                if (deq.empty() || arr[j % n] >= deq.back().first)
                    deq.emplace_back(arr[j % n], j);
            }
        } else if (arr[i % n] >= deq.back().first) {
            deq.emplace_back(arr[i % n], i);
        }

        cout << deq.back().first << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
