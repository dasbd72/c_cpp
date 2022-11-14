#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    sort(A.begin(), A.end());
    queue<tuple<vector<int>, int>> que;
    set<vector<int>> st;
    que.emplace(vector<int>(N, 0), 1);
    st.emplace(vector<int>(N, 0));
    int step = -1;
    while (!que.empty() && step == -1) {
        auto cur_A = get<0>(que.front());
        auto cur_step = get<1>(que.front());
        que.pop();
        for (int i = 0; i < N; i++) {
            auto nxt_A = cur_A;
            if (cur_A[i] == 0) {
                nxt_A[i] = A[i];
            } else {
                nxt_A[i] = 0;
            }
            if (nxt_A[i] == Q) {
                step = cur_step;
                break;
            } else if (st.find(nxt_A) == st.end()) {
                st.emplace(nxt_A);
                que.emplace(nxt_A, cur_step + 1);
            }
        }
        for (int i = 0; i < N; i++) {
            if (cur_A[i]) {
                for (int j = 0; j < N; j++) {
                    if (i != j) {
                        auto nxt_A = cur_A;
                        int amount = min(A[j] - cur_A[j], cur_A[i]);
                        nxt_A[i] -= amount;
                        nxt_A[j] += amount;
                        if (nxt_A[i] == Q || nxt_A[j] == Q) {
                            step = cur_step;
                            break;
                        } else if (st.find(nxt_A) == st.end()) {
                            st.emplace(nxt_A);
                            que.emplace(nxt_A, cur_step + 1);
                        }
                    }
                }
                if (step != -1) {
                    break;
                }
            }
        }
    }
    cout << step << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}