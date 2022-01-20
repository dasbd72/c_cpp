#include <iostream>

// Iterative Merge Sort
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

// Recursive version
template <class T>
void Merge(T arr[], const int left, const int mid, const int right) {
    T *a = new T[mid - left];
    T *b = new T[right - mid];
    std::copy(arr + left, arr + mid, a);
    std::copy(arr + mid, arr + right, b);
    int l = 0, r = 0, k = 0;
    while (l < mid - left && r < right - mid)
        arr[left + k++] = (a[l] < b[r] ? a[l++] : b[r++]);
    while (l < mid - left)
        arr[left + k++] = a[l++];
    while (r < right - mid)
        arr[left + k++] = b[r++];
    delete[] a;
    delete[] b;
}

template <class T>
void MergeSort(T arr[], int left, int right) {
    if (left + 1 >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid, right);
    Merge(arr, left, mid, right);
}

int main() {
    int arr[] = {6, 7, 7, 7, 5, 3, 1, 2, 3};
    // MergeSort_iter(arr, 9);
    MergeSort(arr, 0, 9);
    for (auto x : arr) std::cout << x << " ";
    std::cout << "\n";
}