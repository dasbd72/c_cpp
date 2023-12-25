#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll n) {
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

class PrimeSieve {
    vector<int> primes;
    vector<bool> is_p;

   public:
    void sieve(int n) {
        primes.clear();
        is_p.assign(n + 1, true);
        is_p[0] = is_p[1] = false;
        for (int i = 2; i < n; ++i) {
            if (is_p[i])
                primes.emplace_back(i);
            for (auto p : primes) {
                if (1LL * i * p > n)
                    break;
                is_p[i * p] = false;
                if (i % p == 0)
                    break;
            }
        }
    }
    bool is_prime(int n) {
        return is_p[n];
    }
};

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// ax + by = c
// return (x, y)
pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)
        return {1, 0};
    auto [x, y] = extgcd(b, a % b);
    return {y, x - a / b * y};
}

// only when gcd(a, m) == 1
ll inv_mod(ll a, ll m) {
    auto [x, y] = extgcd(a, m);
    return (x % m + m) % m;
}

vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res.emplace_back(n);
    return res;
}