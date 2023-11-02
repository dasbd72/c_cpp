#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;

    queue<vector<int> > que;
    set<vector<int> > st;
    bool done = false;
    int steps;
    int ans = -1;

    auto push_state = [&](vector<int> state) {
        for (auto val : state) {
            if (val == q) {
                done = true;
                ans = steps;
                return;
            }
        }
        if (st.find(state) == st.end()) {
            que.emplace(state);
            st.emplace(state);
        }
    };

    push_state(vector<int>(n, 0));

    for (steps = 1; !que.empty() && !done; steps++) {
        for (int len = que.size(); len-- && !done;) {
            vector<int> curr_state = que.front();
            que.pop();
            for (int i = 0; i < n && !done; i++) {
                {
                    vector<int> next_state = curr_state;
                    // empty or fill
                    if (next_state[i])
                        next_state[i] = 0;
                    else
                        next_state[i] = arr[i];
                    push_state(next_state);
                }

                if (curr_state[i] == 0)
                    continue;

                // transfer to another
                for (int j = 0; j < n && !done; j++) {
                    if (j == i)
                        continue;
                    vector<int> next_state = curr_state;
                    int amount = min(arr[j] - next_state[j], next_state[i]);
                    next_state[j] += amount;
                    next_state[i] -= amount;
                    push_state(next_state);
                }
            }
        }
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
