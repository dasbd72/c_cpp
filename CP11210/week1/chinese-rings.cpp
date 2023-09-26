#include <bits/stdc++.h>
using namespace std;

void print(int i, bool is_in) {
    cout << "Move ring " << i << (is_in ? " in\n" : " out\n");
}
void remove(int i);
void restore(int i);
void remove(int i) {
    if (i <= 0)
        return;
    remove(i - 2);
    print(i, false);
    restore(i - 2);
    remove(i - 1);
}
void restore(int i) {
    if (i <= 0)
        return;
    restore(i - 1);
    remove(i - 2);
    print(i, true);
    restore(i - 2);
}
void solve() {
    int n;
    cin >> n;
    remove(n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}