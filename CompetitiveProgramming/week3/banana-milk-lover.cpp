#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long data_t;
typedef tuple<data_t, data_t, vector<data_t>, int> mytype;
bool compare(mytype a, mytype b) {
    auto [a_sum, a_max, a_vec, a_order] = a;
    auto [b_sum, b_max, b_vec, b_order] = b;
    if(a_sum != b_sum)
        return (a_sum > b_sum);
    if(a_max != b_max)
        return (a_max > b_max);
    if(a_vec.size() != b_vec.size())
        return (a_vec.size() > b_vec.size());
    return a_order < b_order;
}
void solve() {
    int T;
    cin >> T;
    while(T--) {
        int N, Ki;
        vector<mytype> A;
        cin >> N;
        for(int i = 0; i < N; i++) {
            vector<data_t> Ai;
            cin >> Ki;
            data_t sumAi = 0, maxAi = 0, Aij;
            for(int k = 0; k < Ki; k++) {
                cin >> Aij;
                sumAi += Aij;
                maxAi = max(maxAi, Aij);
                Ai.emplace_back(Aij);
            }
            A.emplace_back(sumAi, maxAi, Ai, i);
        }
        sort(A.begin(), A.end(), compare);
        for(int i = 0; i < N; i++) {
            bool first = true;
            auto Ai = get<2>(A[i]);
            for(auto a : Ai) {
                if(first)
                    first = false;
                else
                    cout << " ";
                cout << a;
            }
            cout << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2