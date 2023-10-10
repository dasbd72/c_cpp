#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, m, n;
    cin >> k >> n >> m;
    k++;
    vector<long long> a(n + 1);
    vector<long long> b(m + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[n - 1] != k)
        a[n++] = k;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (b[m - 1] != k)
        b[m++] = k;

    int i = 0, j = 0;
    int da = 1, db = 0;
    long long prev = 2, diff = 0;
    long long off = 1, prev_off = 1;
    long long purples = 0;
    while (i < n && j < m) {
        prev_off = off;
        if (a[i] < b[j]) {
            diff = a[i] - prev;
            off += (da - db) * diff;

            prev = a[i];
            i++;
            da = !da;
        } else if (a[i] > b[j]) {
            diff = b[j] - prev;
            off += (da - db) * diff;

            prev = b[j];
            j++;
            db = !db;
        } else {
            diff = a[i] - prev;
            off += (da - db) * diff;

            prev = a[i];
            i++, j++;
            da = !da, db = !db;
        }

        if ((prev_off < 0 && off > 0) || (prev_off > 0 && off < 0)) {
            purples += 1;
        }
        if (off == 0 && prev_off == 0) {
            purples += diff;
        } else if (off == 0) {
            purples += 1;
        }
    }
    printf("%lld %lld %lld\n", k - purples - 1, k - purples - 1, purples);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}