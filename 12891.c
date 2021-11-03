#include <stdio.h>

int main(void) {
    int m, n, K, i, j, a, b, operation, square, size = 0, ans = 0;
    scanf("%d %d %d", &m, &n, &K);
    int matrix[m][n], z[m][n], vector[1000] = {};
    //輸入陣列
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            z[i][j] = matrix[i][j];
        }
    }
    //進行operations
    for (i = 0; i < K; i++) {
        scanf("%d %d %d", &operation, &a, &b);
        if (operation == 0) {
            for (j = 0; j < n; j++) {
                matrix[a][j] = z[b][j];
                matrix[b][j] = z[a][j];
                z[b][j] = matrix[b][j];
                z[a][j] = matrix[a][j];
            }
        } else {
            for (j = 0; j < n; j++) {
                z[a][j] = matrix[a][j] = matrix[a][j] + matrix[b][j];
            }
        }
    }
    //計算大小，並比較
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            vector[i] = vector[i] + matrix[i][j] * matrix[i][j];
        }
        if (vector[i] >= size) {
            size = vector[i];
            ans = i;
        }
    }
    //輸出結果
    for (j = 0; j < n - 1; j++) {
        printf("%d ", matrix[ans][j]);
    }
    printf("%d\n", matrix[ans][n - 1]);
    return 0;
}