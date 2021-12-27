#include <iostream>
long long fastPow(long long a, long long n, long long m);
long long decrypt(long long C, long long d, long long n);
long long encrypt(long long M, long long e, long long n);
int main() {
    using namespace std;
    int x;
    while (cin >> x) {
        cout << x << " : " << encrypt(x, 211, 2419) << "\n";
    }
}

long long fastPow(long long a, long long n, long long m) {
    if (n == 0)
        return 1;
    long long tmp = fastPow(a, n / 2, m);
    tmp = (tmp * tmp) % m;
    if (n % 2)
        tmp = (tmp * a) % m;
    return tmp;
}
long long decrypt(long long C, long long d, long long n) {
    return fastPow(C, d, n);
}
long long encrypt(long long M, long long e, long long n) {
    return fastPow(M, e, n);
}