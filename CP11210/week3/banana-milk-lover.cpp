#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int N;
    cin >> N;
    vector<vector<int> > groups;
    vector<tuple<unsigned long long, int, int, int> > compare_list;
    for (int i = 0; i < N; i++) {
        int K, largest = 0;
        unsigned long long sum = 0;
        cin >> K;
        vector<int> group(K);
        for (int j = 0; j < K; j++) {
            cin >> group[j];
            sum += group[j];
            largest = max(largest, group[j]);
        }
        groups.emplace_back(group);
        compare_list.emplace_back(sum, largest, K, -i);
    }
    sort(compare_list.begin(), compare_list.end(), greater<tuple<unsigned long long, int, int, int> >());

    for (auto tp : compare_list) {
        int idx = -get<3>(tp);
        for (int i = 0; i < (int)groups[idx].size(); i++) {
            cout << groups[idx][i] << (i == (int)groups[idx].size() - 1 ? "\n" : " ");
        }
    }
}
void solve() {
    int T;
    cin >> T;
    while (T--)
        test_case();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
