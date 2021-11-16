#include <stdio.h>
#include <string.h>
int main() {
    char A[1005], B[1005];
    int T, lenA, lenB, posA;
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", A, B);
        lenA = strlen(A);
        lenB = strlen(B);
        for (int posA = 0; posA < lenA; posA++) {
            int i = posA;
            for (int posB = 0; A[i] == B[posB] && i < lenA && posB < lenB; posB++, i++) {
            }
        }
    }
}