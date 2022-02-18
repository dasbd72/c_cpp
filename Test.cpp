#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<pair<int, int>>& arr, int l, int r, int val) {
    int m;
    while (l + 1 <= r) {
        m = (l + r) / 2;
        if (arr[m].first < val)
            r = m;
        else if (arr[m].first > val)
            l = m + 1;
        else
            return m;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int, int>> arr;
    arr.push_back({2, 0});
    arr.push_back({5, 0});
    arr.push_back({9, 0});
    arr.push_back({7, 0});
    arr.push_back({12, 0});
    cout << binary_search(arr, 0, 5, 4) << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 c.cpp ; ./a.out <c.in