#include<stdlib.h>
#include<math.h>
int** malloc_ptr(int array_size){
    return (int**)malloc(array_size * sizeof(int*));
}
void malloc_array(int **array, int array_size){
    *array = (int*)malloc(array_size * sizeof(int));
}
void pointer_ptr_to_array(int *array, int **ptr,int N){
    for(int i = 0; i < N; i++)
        ptr[i] = array + ((1+i)*i)/2;
}