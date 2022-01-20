#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long a, long long n, long long m);
long long decrypt(long long C, long long d, long long n);
long long encrypt(long long M, long long e, long long n);
long long RSA_d(long long e, long long phi);
long long eulerphi(long long n);
long long gcd(long long a, long long b);
bool iscoprime(long long a, long long b);
bool isprime(long long n);

int main() {
    // int x;
    // while (cin >> x) {
    //     cout << x << " : " << encrypt(x, 211, 2419) << "\n";
    // }

    // cout << RSA_d(101, 720) << endl;

    vector<int> ciphertext = {299, 656, 280, 47, 216};
    for (auto text : ciphertext) {
        cout << char(decrypt(text, 221, 779) + 'a' - 27) << ' ';
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
long long RSA_d(long long e, long long phi) {
    long long d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    return d;
}
long long eulerphi(long long n) {
    if (n == 1)
        return 1;
    if (isprime(n))
        return n - 1;
    long long ans = 1;
    for (int i = 2; i < n; i++) {
        // if (n % i == 0 && isprime(i)) ans *= (i-1) * pow(i, log)
    }
    return 0;
}
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    if (a > b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}
bool iscoprime(long long a, long long b) {
    return gcd(a, b) == 1;
}
bool isprime(long long n) {
    if (n <= 2)
        return true;
    long long n_sqrt = sqrt(n);
    for (int i = 2; i <= n_sqrt; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}