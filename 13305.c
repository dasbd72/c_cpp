#include <stdio.h>
long long prev_sum[1000010];
long long s[1000010];  //全域可以自動初始化
long long sum;
int main(void) {
    int i;
    int M, N, L, R;
    scanf("%d", &N);
    /*O=N+1;
    long long s[O];*/
    for (i = 0; i < N; i++) {
        scanf("%lld", &s[i]);
    }
    //prev_sum[0]=s[0];
    for (i = 0; i < N; i++) {  //為甚麼有if測資二會不過
        // prev_sum[i] = prev_sum[i - 1] + s[i];
        // printf("%lld\n", prev_sum[i - 1]);
        if (i >= 1) {
            prev_sum[i] = prev_sum[i - 1] + s[i];
        } else {
            prev_sum[i] = s[i];
        }
        // printf("%lld\n", prev_sum[i]);
    }
    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &L, &R);
        sum = prev_sum[R - 1] - prev_sum[L - 2];
        printf("%lld\n", sum);
    }
    return 0;
}