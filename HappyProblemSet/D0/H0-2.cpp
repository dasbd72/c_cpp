#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
int getSepSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N;
    vector<int> sepSums(MAXN);
    vector<int> generators(MAXN);
    for (int i = 0; i < MAXN; i++) sepSums[i] = getSepSum(i) + i;
    for (int i = 0; i < MAXN; i++)
        if (sepSums[i] < MAXN && generators[sepSums[i]] == 0)
            generators[sepSums[i]] = i;

    for (cin >> T; T--;) {
        cin >> N;
        cout << generators[N] << '\n';
    }
    return 0;
}
// g++ -std=c++17 H0-2.cpp ; ./a.out <H0-2.in