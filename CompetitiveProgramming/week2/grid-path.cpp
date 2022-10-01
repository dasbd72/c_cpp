#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
long long grid;
int seq[50];
long long lowbit(long long x) {
    return x & (~x + 1);
}
bool dfs(int idx) {
    if (idx == 47) {
        return false;
    }
    while (idx < 48 && seq[idx] != '?') {
        idx++;
    }
}
int main() {
    string S;
    cin >> S;
    for (int i = 0; i < 48; i++) {
        if (S[i] == '?')
            seq[i] = -1;
        else if (S[i] == 'U')
            seq[i] = 0;
        else if (S[i] == 'R')
            seq[i] = 1;
        else if (S[i] == 'D')
            seq[i] = 2;
        else if (S[i] == 'L')
            seq[i] = 3;
    }
}