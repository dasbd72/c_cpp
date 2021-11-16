#include <stdlib.h>
//11711 - Dynamic 3D array
unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k) {
    unsigned dim_2D = n * m;
    unsigned dim_3D = dim_2D * k;
    unsigned ***p3 = (unsigned ***)malloc(n * sizeof(unsigned **));    // allocate an array of size n which contains n unsigned**
    unsigned **p2 = (unsigned **)malloc(dim_2D * sizeof(unsigned *));  // allocate an array of size n*m which contains n*m unsigned*
    unsigned *p1 = (unsigned *)malloc(dim_3D * sizeof(unsigned));      // allocate the memory for all n*m*k elements
    for (unsigned i = 0; i < n; i++) {
        *(p3 + i) = p2 + i * m;
        for (unsigned j = 0; j < m; j++) {
            *(p2 + i * m + j) = p1 + i * m * k + j * k;
        }
    }
    return p3;
}
void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    return;
}
