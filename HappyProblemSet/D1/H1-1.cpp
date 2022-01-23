#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long prevNum, cost, x;
    cin >> N;
    prevNum = 0;
    cost = 0;
    while (N--) {
        cin >> x;
        if (x < prevNum)
            cost += prevNum - x;
        else
            prevNum = x;
    }
    cout << cost << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H1-1.cpp ; ./a.out <H1-1.in