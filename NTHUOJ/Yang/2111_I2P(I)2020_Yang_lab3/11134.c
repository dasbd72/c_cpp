#include<stdio.h>
int main()
{
    int k, arr[]={0,1,2,3,4};
    scanf("%d",&k);
    while(k--)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        arr[x] += arr[y];
        arr[y] = arr[x] - arr[y];
        arr[x] = arr[x] - arr[y];
    }
    for(int i = 0; i < 5; i++) i == 4 ? printf("%d", arr[i]) : printf("%d ", arr[i]);
    return 0;
}