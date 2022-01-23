#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int fac_2 = 0;
    int fac_5 = 0;
    cin >> N;
    for (int i = 2; i <= N; i *= 2)
        fac_2 += N / i;
    for (int i = 5; i <= N; i *= 5)
        fac_5 += N / i;
    cout << min(fac_2, fac_5) << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H1-2.cpp ; ./a.out <H1-2.in