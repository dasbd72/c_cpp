#include <bits/stdc++.h>
using namespace std;
int cntHanoi(int N) {
    if (N == 1)
        return 1;
    return cntHanoi(N - 1) * 2 + 1;
}
void hanoi(int N, int A, int B, int C) {
    if (N == 0)
        return;
    hanoi(N - 1, A, C, B);
    cout << A << ' ' << C << '\n';
    hanoi(N - 1, B, A, C);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cout << cntHanoi(N) << '\n';
    hanoi(N, 1, 2, 3);
    return 0;
}
// g++ H0-5.cpp ; ./a.out <H0-5.in