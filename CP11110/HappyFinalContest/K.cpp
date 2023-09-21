#include <bits/stdc++.h>
using namespace std;
int N, height, head, tail;
vector<int> arr;
vector<int> seg;
void build(int pos) {
    if (pos >= head) {
        if (pos <= tail)
            seg[pos] = arr[pos - head];
        else
            seg[pos] = 0;
        return;
    }
    build(pos * 2);
    build(pos * 2 + 1);
    seg[pos] = seg[pos * 2] | seg[pos * 2 + 1];
}
void solve() {
    cin >> N;
    height = ceil(log2(N + 1));
    head = pow(2, height - 1);
    tail = head + N - 1;
    arr = vector<int>(N);
    seg = vector<int>(4 * (N + 1));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    build(1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 K.cpp ; ./a.out <K.in