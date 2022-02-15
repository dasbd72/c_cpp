#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, A, B;
    long long arr[200001];
    long long prefixsum[200001] = {};
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }

    while (Q--) {
        cin >> A >> B;
        cout << prefixsum[B] - prefixsum[A - 1] << "\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-0.cpp ; ./a.out <T1-0.in