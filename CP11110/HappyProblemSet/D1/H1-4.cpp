#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr(200001);
    int N, X;

    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    int lp = 1, rp = 1;
    int currval = arr[1];
    long long cnt = (arr[1] == X ? 1 : 0);

    while (1) {
        if (rp + 1 <= N && currval + arr[rp + 1] <= X) {
            currval += arr[rp + 1];
            rp++;
        } else if (lp < rp) {
            currval -= arr[lp];
            lp++;
        } else if (rp + 1 <= N) {
            rp = lp = rp + 1;
            currval = arr[rp];
        } else {
            break;
        }
        if (currval == X)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H1-4.cpp ; time ./a.out <H1-4.in