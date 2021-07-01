#include<stdio.h>
//Mexican Wave
int main()
{
    int T, n, m, t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &t);
        //
        for(int i = 0; i < n && i < t-m; i++) printf("-");
        for(int i = 0; i < t && i < m && i < n-t+m; i++) printf("^");
        for(int i = 0; i < n-t; i++) printf("-");
        printf("\n");
    }
    return 0;
}