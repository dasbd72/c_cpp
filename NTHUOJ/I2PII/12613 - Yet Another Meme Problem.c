#include <math.h>
#include <stdio.h>
int main() {
    int T;
    long long A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", (long long)(log10(B + 1)) * A);
    }
}