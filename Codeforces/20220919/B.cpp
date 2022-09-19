#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        if (y > x)
            swap(x, y);  // x > y

        if (y != 0 || x == 0 || (n - 1) % x != 0) {
            cout << "-1\n";
        } else {
            int winner = 1;
            int cnt = 0;
            for(int i = 1; i < n; i++) {
                if(cnt == x) {
                    winner = i + 1;
                    cnt = 1;
                } else {
                    cnt++;
                }
                cout << winner << (i == n - 1 ? "\n" : " ");
            }
        }
    }
    return 0;
}