#include <bits/stdc++.h>
using namespace std;

int hanoi_calc(int i) {
    if (i <= 0)
        return 0;
    return hanoi_calc(i - 1) * 2 + 1;
}
void hanoi(int i, int from, int mid, int to) {
    if (i <= 0)
        return;
    hanoi(i - 1, from, to, mid);
    cout << from << " " << to << "\n";
    hanoi(i - 1, mid, from, to);
}
void solve() {
    int n;
    cin >> n;
    cout << hanoi_calc(n) << "\n";
    hanoi(n, 1, 2, 3);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}