#include <bits/stdc++.h>
using namespace std;
#define MAXA 1000001
#define MAXN 200001
bool isprime[MAXA];
bool calcisprime(int num) {
    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < MAXA; i++) {
        isprime[i] = calcisprime(i);
    }

    int T;
    int N, E;
    long long cnt;
    vector<int> arr(MAXN);
    vector<int> left_ones(MAXN);
    vector<int> right_ones(MAXN);

    for (cin >> T; T--;) {
        cin >> N >> E;
        cnt = 0;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        for (int i = 1; i <= N; i++) {
            if (i - E >= 1 && arr[i - E] == 1)
                left_ones[i] = left_ones[i - E] + 1;
            else
                left_ones[i] = 0;
        }
        for (int i = N; i >= 1; i--) {
            if (i + E <= N && arr[i + E] == 1)
                right_ones[i] = right_ones[i + E] + 1;
            else
                right_ones[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            if (isprime[arr[i]])
                cnt += (long long)(left_ones[i] + 1) * (long long)(right_ones[i] + 1) - 1;
        }
        cout << cnt << "\n";
    }
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H1-3.cpp ; time ./a.out <H1-3.in