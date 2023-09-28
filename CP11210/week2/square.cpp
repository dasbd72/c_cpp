#include <bits/stdc++.h>
using namespace std;

bool recursive(const vector<int> &arr, const int side, vector<int> &sides, int idx) {
    if (sides[0] == side && sides[1] == side && sides[2] == side)
        return true;
    if (idx == (int)arr.size())
        return true;

    for (int i = 0; i < 4; i++) {
        if (sides[i] + arr[idx] > side)
            continue;
        sides[i] += arr[idx];
        if (recursive(arr, side, sides, idx + 1))
            return true;
        sides[i] -= arr[idx];
        // Core
        // With others or not, else its an exactly same branch
        if (sides[i] == 0)
            return false;
    }
    return false;
}
bool get_ans(const vector<int> &arr) {
    int side = 0;
    for (auto x : arr)
        side += x;
    if (side % 4 != 0)
        return false;
    side /= 4;
    for (auto x : arr)
        if (x > side)
            return false;
    vector<int> sides(4, 0);
    return recursive(arr, side, sides, 0);
}
void test_case() {
    int m;
    cin >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    if (get_ans(arr))
        cout << "yes\n";
    else
        cout << "no\n";
}
void solve() {
    int n;
    cin >> n;
    while (n--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}