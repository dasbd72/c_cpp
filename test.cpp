#include <bits/stdc++.h>
using namespace std;
int main() {
    long long idx[5] = {0};
    for (idx[0] = 1; idx[0] <= 9; idx[0]++) {
        for (idx[1] = idx[0] + 1; idx[1] <= 9; idx[1]++) {
            for (idx[2] = idx[1] + 1; idx[2] <= 9; idx[2]++) {
                for (idx[3] = idx[2] + 1; idx[3] <= 9; idx[3]++) {
                    for (idx[4] = idx[3] + 1; idx[4] <= 9; idx[4]++) {
                        long double square_sum = 0, square_sum_root;
                        for (int i = 0; i < 5; i++) square_sum += idx[i] * idx[i];
                        square_sum_root = sqrtf(square_sum);
                        if (square_sum_root == long(square_sum_root)) {
                            for (int i = 0; i < 5; i++) cout << idx[i] << " ";
                            cout << square_sum_root << "\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}