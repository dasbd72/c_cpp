// 12613.c
#include <stdio.h>
#include <math.h>
#define ll long long
// b+1 == 10^intlen(b)
int main(){
    int T;
    ll A, B;
    for(scanf("%d", &T); T--;){
        scanf("%lld %lld", &A, &B);
        printf("%lld\n" , (ll)log10(B+1) * A);
    }
}