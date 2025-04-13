#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (check(R) == true)
        return {R, R + 1};
    if (check(L) == false)
        return {L - 1, L};
    while (L + 1 < R) {
        Ty Mid = L + (R - L) / 2;
        if (check(Mid))
            L = Mid;
        else
            R = Mid;
    }
    return {L, R};
}