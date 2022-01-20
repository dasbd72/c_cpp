#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long a, long long n, long long m) {
    if (n == 0)
        return 1;
    long long tmp = fastPow(a, n / 2, m);
    tmp = (tmp * tmp) % m;
    if (n % 2)
        tmp = (tmp * a) % m;
    return tmp;
}
int main() {
    cout << fastPow(53, 20, 100) << endl;
}