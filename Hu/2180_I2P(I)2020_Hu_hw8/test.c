#include <stdio.h>
#include <stdlib.h>
#include "12511.h"
#include <math.h>
int main()
{
    int arr[] = {1, 5, 6, 2, 3, 4};
    merge_sort(arr, arr+5);
    for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
}