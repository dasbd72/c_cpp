#include <iostream>
#include <vector>
using namespace std;
int inparr[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, last_neg_pos, lpos, rpos, cpos;
    while (cin >> N) {
        last_neg_pos = -1;
        for (int i = 0; i < N; i++) {
            cin >> inparr[i];
            if (inparr[i] < 0)
                last_neg_pos = i;
        }
        lpos = last_neg_pos;
        rpos = last_neg_pos + 1;
        cpos = 0;
        while (lpos >= 0 || rpos < N) {
            if (lpos >= 0 && rpos < N) {
                if (-inparr[lpos] <= inparr[rpos])
                    cout << inparr[lpos--];
                else
                    cout << inparr[rpos++];
            } else if (lpos >= 0) {
                cout << inparr[lpos--];
            } else {
                cout << inparr[rpos++];
            }
            cout << (cpos == N - 1 ? '\n' : ' ');
            cpos++;
        }
    }
}