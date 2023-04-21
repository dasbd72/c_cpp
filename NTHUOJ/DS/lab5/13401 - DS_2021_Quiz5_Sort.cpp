#include <bits/stdc++.h>
using namespace std;

template <class T>
void MergeSort_iter(T arr[], int len) {
    T *a = arr;
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low, mid, high, start1, start2, end1, end2, k;
            k = low = start;
            mid = std::min(start + seg, len);
            high = std::min(start + seg + seg, len);
            start1 = low, end1 = mid;
            start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = (a[start1] < a[start2] ? a[start1++] : a[start2++]);
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        std::swap(a, b);
    }
    if (a != arr) {
        std::copy(b, b + len, a);
        b = a;
    }
    delete[] b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    long long dis = 0;
    pair<int, int> *arr;
    cin >> N >> M;
    arr = new pair<int, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    MergeSort_iter(arr, N);

    dis += abs(arr[0].second - arr[0].first);
    for (int i = 1; i < N; i++) {
        dis += abs(arr[i].second - arr[i].first) + abs(arr[i].second - arr[i].first);
    }
    dis += abs(arr[0].second - M);
    cout << dis << "\n";
    return 0;
}