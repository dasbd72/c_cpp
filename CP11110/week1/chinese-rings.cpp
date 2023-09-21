#include <bits/stdc++.h>
using namespace std;
void move_out(int x) {
    cout << "Move ring " << x << " out\n";
}
void move_in(int x) {
    cout << "Move ring " << x << " in\n";
}
void cr_in(int x);
void cr_out(int x) {
    if(x <= 0)
        return;
    cr_out(x - 2);
    move_out(x);
    cr_in(x - 2);
    cr_out(x - 1);
}
void cr_in(int x) {
    if(x <= 0)
        return;
    cr_in(x - 1);
    cr_out(x - 2);
    move_in(x);
    cr_in(x - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cr_out(n);
    return 0;
}