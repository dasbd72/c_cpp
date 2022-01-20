#include <stdio.h>
#include <string.h>
int main() {
    char A[10];
    char B[100];
    int N, lenA, lenB;
    int maximum = 0, cnt;
    scanf("%s %d", A, &N);
    lenA = strlen(A);
    while (N--) {
        scanf("%s", B);
        cnt = 0;
        lenB = strlen(B);
        for (int i = 0; i < lenB - lenA; i++) {
        }
        maximum = cnt > maximum ? cnt : maximum;
    }
}