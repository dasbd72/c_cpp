#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, A, B;
    cin >> N >> Q;
    vector<int> arr(N + 1);
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] ^ arr[i];
    }
    while (Q--) {
        cin >> A >> B;
        cout << (prefix[B] ^ prefix[A - 1]) << "\n";
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-5.cpp ; ./a.out <T1-5.in