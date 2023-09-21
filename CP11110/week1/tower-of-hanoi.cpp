#include <bits/stdc++.h>
using namespace std;
void hanoi(int n, int a, int b, int c, queue<pair<int, int>>& que) {
    if(n == 0) 
        return;
    hanoi(n - 1, a, c, b, que);
    que.emplace(a, c);
    hanoi(n - 1, b, a, c, que);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    queue<pair<int, int>> que;
    cin >> n;
    hanoi(n, 1, 2, 3, que);
    cout << que.size() << "\n";
    while(!que.empty()) {
        cout << que.front().first << " " << que.front().second << "\n";
        que.pop();
    }
    return 0;
}