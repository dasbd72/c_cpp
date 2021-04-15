#include<stdio.h>
#define MAXN (500+5)
int main()
{
    int n, q, a[MAXN];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    while(q--)
    {
        int l, r, count[501]={}, max = 0, ans;
        scanf("%d %d", &l, &r);
        for(int i = l; i <= r; i++)
        {
            count[a[i]] ++;
            if(count[a[i]] > max) ans = a[i], max = count[a[i]];
            else if(count[a[i]] == max) ans = a[i] < ans ? a[i] : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
