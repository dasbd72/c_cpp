#include<math.h>
#include<stdlib.h>
int** s(int* a,int len){
    // any sorting solution
    for(int i = 0; i < len; i++) for(int j = i+1; j < len; j++) if(a[i] > a[j]){
        a[i] += a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
    }
    len = sqrt(len);
    //link the 1D array into a 2D array
    int **dim2arr = (int**)malloc(len * sizeof(int*));
    for(int i = 0; i < len; i++)
        dim2arr[i] = a + i*len;
    return dim2arr;
}