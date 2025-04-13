#include <bits/stdc++.h>
using namespace std;

inline int __lg(int __n) {
    // __builtin_clz gets number of zeros from left until the first one
    return sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(__n);
}
unsigned getLCA(unsigned a, unsigned b) {
    if (a < b)
        b >>= __lg(b) - __lg(a);
    else
        a >>= __lg(a) - __lg(b);
    return a >> (__lg(a ^ b) + (a != b));
}