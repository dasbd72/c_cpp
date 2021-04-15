#include<stdio.h>
int main(){
    int a, n, d;
    scanf("%d %d %d", &a, &n, &d);
    int ans1 = a + (n-1)*d, ans2 = (2*a + (n-1)*d) * n / 2;
    printf("%d %d", ans1, ans2);
}