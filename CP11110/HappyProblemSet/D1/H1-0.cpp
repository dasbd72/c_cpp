#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int len;
    cin >> N;
    len = pow(2, N);
    for (int i = 0; i < len; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (i >= pow(2, j) && ((i - (int)pow(2, j)) / (int)pow(2, j + 1)) % 2 == 0)
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H1-0.cpp ; ./a.out <H1-0.in