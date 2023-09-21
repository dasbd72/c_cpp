#include <bits/stdc++.h>
using namespace std;
void solve(int A[], int N, int M, vector<int>& vec) {
    if(vec.size() == M) {
        for(int i = 0; i < M; i++) {
            cout << A[vec[i]] << (i == M - 1 ? "\n" : " ");
        }
        return;
    }
    int start = 0;
    if(vec.size() != 0) 
        start = *vec.rbegin() + 1;
    for(int i = start; i < N; i++) {
        vec.push_back(i);
        solve(A, N, M, vec);
        vec.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    int A[25];
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> vec;
    solve(A, N, M, vec);
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 c.cpp ; ./a.out < c.in
// g++ -std=c++17 -Wall -Wextra -g -O2 c.cpp ; ./a.exe