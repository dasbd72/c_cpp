// AC
#include <stdio.h>
#include <string.h>
#define MAXSIZE 1005
int count(char arr[MAXSIZE][MAXSIZE], int row, int col, int dr, int dc, int N, int M, char c) {
    int maximum = 0, count = 0;
    while (row <= N && col <= M && row >= 1 && col >= 1) {
        if (arr[row][col] == c) {
            count++;
            if (count > maximum) maximum = count;
        } else {
            count = 0;
        }
        row += dr;
        col += dc;
    }
    return maximum;
}
int main() {
    int T, N, M;
    int maximumO, tempO, maximumS, tempS;                              // O for 'o', S for '#'(sharp)
    char arr[MAXSIZE][MAXSIZE];                                        // Use from [1~N][1~M] to prevent runtime error
    scanf("%d", &T);                                                   // Get T
    while (T--) {                                                      // Run T times
        maximumO = maximumS = 0;                                       // Initialize
        scanf("%d %d", &N, &M);                                        // Get N and M
        for (int r = 0; r < MAXSIZE; r++) memset(arr[r], 0, MAXSIZE);  // Clean arr to all 0
        for (int r = 1; r <= N; r++) scanf("%s", arr[r] + 1);          // Scan the line from arr[r][1] to arr[r][M]
        for (int r = 1; r <= N; r++) {
            tempO = count(arr, r, 1, 0, 1, N, M, 'o');  //go right from r, 1
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, r, 1, 0, 1, N, M, '#');  //go right from r, 1
            if (tempS > maximumS) maximumS = tempS;
            tempO = count(arr, r, 1, -1, 1, N, M, 'o');  // go up right from r, 1
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, r, 1, -1, 1, N, M, '#');  // go up right from r, 1
            if (tempS > maximumS) maximumS = tempS;
            tempO = count(arr, r, 1, 1, 1, N, M, 'o');  // go down right from r, 1
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, r, 1, 1, 1, N, M, '#');  // go down right from r, 1
            if (tempS > maximumS) maximumS = tempS;
        }
        for (int c = 1; c <= M; c++) {
            tempO = count(arr, 1, c, 1, 0, N, M, 'o');  //go down from 1, c
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, 1, c, 1, 0, N, M, '#');  //go down from 1, c
            if (tempS > maximumS) maximumS = tempS;
            tempO = count(arr, N, c, -1, 1, N, M, 'o');  // go up right from N, c
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, N, c, -1, 1, N, M, '#');  // go up right from N, c
            if (tempS > maximumS) maximumS = tempS;
            tempO = count(arr, 1, c, 1, 1, N, M, 'o');  // go down right from 1, c
            if (tempO > maximumO) maximumO = tempO;
            tempS = count(arr, 1, c, 1, 1, N, M, '#');  // go down right from 1, c
            if (tempS > maximumS) maximumS = tempS;
        }
        printf("%d %d\n", maximumO, maximumS);
    }
}