#include <bits/stdc++.h>
using namespace std;
long long inv;
void merge(vector<int> &arr, int l, int m, int r) {
    vector<int> larr(arr.begin() + l, arr.begin() + m + 1);
    vector<int> rarr(arr.begin() + m + 1, arr.begin() + r + 1);

    larr.emplace_back(1e9);
    rarr.emplace_back(1e9);

    auto itl = larr.begin();
    auto itr = rarr.begin();

    for (auto it = arr.begin() + l; it <= arr.begin() + r; it++) {
        if (*itl <= *itr) {
            *it = *itl;
            itl++;
        } else {
            *it = *itr;
            itr++;
            inv += larr.end() - itl - 1;
        }
    }
}
void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void solve(int N) {
    vector<int> arr;
    for (int i = 0, A; i < N; i++) {
        cin >> A;
        arr.emplace_back(A);
    }
    inv = 0;
    mergeSort(arr, 0, N - 1);
    cout << inv << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N) {
        if (N == 0)
            break;
        solve(N);
    };
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T1-4.cpp ; ./a.out <T1-4.in