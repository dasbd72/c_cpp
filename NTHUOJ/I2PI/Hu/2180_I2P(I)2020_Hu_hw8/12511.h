#include<math.h>
#include<stdlib.h>
void merge_sort(int *L, int *R){
    if(L+1 == R) return;
    int *M = (R-L)/2 + L;
    int li = 0, ri = 0, ai = 0;
    int *larr = (int*)malloc((M-L)*sizeof(int)), *rarr = (int*)malloc((R-M)*sizeof(int));
    merge_sort(L, M);
    merge_sort(M, R);
    for(int i = 0; i < M-L; i++) larr[i] = *(L+i);
    for(int i = 0; i < R-M; i++) rarr[i] = *(M+i);
    while(L + li < M && M + ri < R){
        if(larr[li] <= rarr[ri]) L[ai++] = larr[li++];
        else L[ai++] = rarr[ri++];
    }
    while(L + li < M) L[ai++] = larr[li++];
    while(M + ri < R) L[ai++] = rarr[ri++];
    return;
}
int** s(int* a,int len){
    // any sorting solution
    merge_sort(a, a+len);
    len = sqrt(len);
    //link the 1D array into a 2D array
    int **dim2arr = (int**)malloc(len * sizeof(int*));
    for(int i = 0; i < len; i++)
        dim2arr[i] = a + i*len;
    return dim2arr;
}
