template <class T>
void QuickSort(T *arr, const int left, const int right) {
    // int arr[8] = {10, 9, 7, 1, 2, 3, 4, 5};
    // QuickSort(arr, 0, 7);
    if (left < right) {
        int i = left, j = right + 1;
        T pivot = arr[left];
        do {
            do i++;
            while (arr[i] < pivot);
            do j--;
            while (arr[j] > pivot);
            if (i < j)
                std::swap(arr[i], arr[j]);
        } while (i < j);
        std::swap(arr[left], arr[j]);
        QuickSort(arr, left, j - 1);
        QuickSort(arr, j + 1, right);
    }
}