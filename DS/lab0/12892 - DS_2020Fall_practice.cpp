#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X, left, right, mid;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    while (cin >> X) {
        left = 0;
        right = N;
        while (right > left) {
            mid = (left + right) / 2;
            if (X > arr[mid]) {
                left = mid + 1;
            } else if (X < arr[mid]) {
                right = mid;
            } else {
                cout << mid << endl;
                break;
            }
        }
    }
}