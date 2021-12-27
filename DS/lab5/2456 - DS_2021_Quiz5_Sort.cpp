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
    int N, M;
    int S, E;
    vector<pair<int, int>> right, left;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S >> E;
        if (E > S)
            right.push_back(make_pair(S, E));
        else if (S > E)
            left.push_back(make_pair(S, E));
    }
}