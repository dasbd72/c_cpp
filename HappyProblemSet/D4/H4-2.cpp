#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<pair<int, int>>& arr, int l, int r, int val) {
    int m;
    while (l + 1 <= r) {
        m = (l + r) / 2;
        if (arr[m].first < val)
            l = m + 1;
        else if (arr[m].first > val)
            r = m;
        else
            return m;
    }
    return -1;
}
bool solve(vector<pair<int, int>>& arr, vector<int>& pos, int cnt, int target) {
    if (cnt == 2) {
        pos[2] = binary_search(arr, pos[1] + 1, arr.size(), target);
        if (pos[2] == -1)
            return false;
        else
            return true;
    }
    for (int i = (cnt == 0 ? 0 : pos[0] + 1); i < arr.size() && arr[i].first <= target; i++) {
        pos[cnt] = i;
        if (arr[i].first <= target && solve(arr, pos, cnt + 1, target - arr[i].first))
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, X;
    vector<pair<int, int>> arr;
    vector<int> pos(3);
    cin >> N >> X;
    for (int i = 1, inp; i <= N; i++) {
        cin >> inp;
        arr.push_back({inp, i});
    }
    sort(arr.begin(), arr.end());

    if (solve(arr, pos, 0, X))
        cout << arr[pos[0]].second << ' ' << arr[pos[1]].second << ' ' << arr[pos[2]].second << '\n';
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H4-2.cpp ; ./a.out <H4-2.in