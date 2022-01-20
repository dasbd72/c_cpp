#include<stdio.h>
int main()
{
    int N, a[205]={}, bd, b0;
    scanf("%d%d%d%d", &N, a, a+1, a+2);
    b0 = a[1] - a[0];
    bd = (a[2] - a[1]) - (a[1] - a[0]);
    //a = a_n-1 + b0 + (n*bd)
    for(int i = 1; i < N; i++)
    {
        a[i] = a[i-1] + b0 + (i-1) * bd;
    }
    for(int i = 0; i < N; i++) i == N-1 ? printf("%d\n", a[i]): printf("%d ", a[i]);
    return 0;
}