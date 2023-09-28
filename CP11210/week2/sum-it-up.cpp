#include <bits/stdc++.h>
using namespace std;

bool recursive(const int tot, const vector<int>& arr, const vector<int>& cnt, int idx, int sum, vector<int>& choice) {
    if (tot == sum) {
        int cur_sum = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            for (int j = 0; j < choice[i]; j++) {
                cur_sum += arr[i];
                cout << arr[i];
                if (cur_sum == sum) {
                    cout << "\n";
                } else {
                    cout << "+";
                }
            }
        }
        return true;
    }
    if (idx == (int)arr.size())
        return false;
    if (sum > tot)
        return false;

    bool ret = false;
    for (int i = cnt[idx]; i >= 0; i--) {
        choice[idx] = i;
        ret = recursive(tot, arr, cnt, idx + 1, sum + i * arr[idx], choice) || ret;
    }
    return ret;
}
bool find_sums(const int tot, const vector<int>& arr, const vector<int>& cnt) {
    vector<int> choice(arr.size(), 0);
    return recursive(tot, arr, cnt, 0, 0, choice);
}
bool test_case() {
    int t, n;
    cin >> t >> n;
    if (t == 0 && n == 0)
        return false;

    cout << "Sums of " << t << ":\n";

    vector<int> arr;
    vector<int> cnt;

    int prev = -1, accu = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (i == 0) {
            prev = x;
            accu = 1;
        } else if (prev != x) {
            arr.emplace_back(prev);
            cnt.emplace_back(accu);
            prev = x;
            accu = 1;
        } else {
            accu++;
        }
    }
    arr.emplace_back(prev);
    cnt.emplace_back(accu);

    if (!find_sums(t, arr, cnt))
        cout << "NONE\n";

    return true;
}
void solve() {
    while (test_case())
        ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}