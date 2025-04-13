#include <bits/stdc++.h>
using namespace std;

template <class FuncTy>
pair<double, double> ternarySearch(double L, double R, FuncTy func, double eps = 1e-6) {
    while (L + eps < R) {
        double LM = L + (R - L) / 3;
        double RM = R - (R - L) / 3;
        if (func(LM) > func(RM))
            L = LM;
        else
            R = RM;
    }
    return {L, R};
}