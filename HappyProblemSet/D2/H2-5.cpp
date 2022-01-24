#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int cnt;
    vector<bool> heads(200001, false);
    cin >> N;
    cnt = 0;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        heads[x] = true;
        if (heads[x - 1] == false)
            cnt++;
        else
            heads[x - 1] = false;
    }
    cout << cnt << "\n";
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-5.cpp ; ./a.out <H2-5.in