#include <bits/stdc++.h>
using namespace std;
long long arr[1000005];
long long tmp[1000005];
long long ans;
void merge(int l, int r) {
    for (int i = l; i <= r; i++)
        tmp[i] = arr[i];

    // int m = (l + r) / 2;
    // int idx = l;
    // int sl = l, sr = m + 1, lrem = m - l + 1;

    // while (sl <= m && sr <= r) {
    //     if (tmp[sl] <= tmp[sr]) {
    //         lrem--;
    //         arr[idx++] = tmp[sl++];
    //     } else {
    //         ans += lrem;
    //         arr[idx++] = tmp[sr++];
    //     }
    // }
    // while (sl <= m) {
    //     lrem--;
    //     arr[idx++] = tmp[sl++];
    // }
    // while (sr <= r) {
    //     ans += lrem;
    //     arr[idx++] = tmp[sr++];
    // }

    int m = (l + r) / 2;
    int idx = l;
    int sl = l, sr = m + 1, rcnt = 0;

    while (sl <= m && sr <= r) {
        if (tmp[sl] <= tmp[sr]) {
            ans += rcnt;
            arr[idx++] = tmp[sl++];
        } else {
            rcnt++;
            arr[idx++] = tmp[sr++];
        }
    }
    while (sl <= m) {
        ans += rcnt;
        arr[idx++] = tmp[sl++];
    }
    while (sr <= r) {
        rcnt++;
        arr[idx++] = tmp[sr++];
    }
}
void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, r);
}
void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ans = 0;
    merge_sort(0, N - 1);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}