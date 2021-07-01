#include<stdio.h>
#define MAXN 500 + 5
int main()
{
    int n, arr[MAXN][MAXN]={};
    scanf("%d",&n);
    int i = 1, layer = n;
    int y = 1, x = 1;
    while(i <= 4*n*n)
    {
        while(x <= n+layer) arr[y][x++] = i++;
        x--;
        y++;
        while(y <= n+layer) arr[y++][x] = i++;
        y--;
        x--;
        while(x >= n-layer+1) arr[y][x--] = i++;
        x++;
        y--;
        while(y >= n-layer+2) arr[y--][x] = i++;
        y++;
        x++;
        layer--;
        // for(int _y = 1; _y <= 2*n; _y++) for(int _x = 1; _x <= 2*n; _x++)
        // {
        //     _x == 2*n ? printf("%d\n", arr[_y][_x]) : printf("%d ", arr[_y][_x]);
        // }
        // printf("--------------------\n");
    }
    for(int _y = 1; _y <= 2*n; _y++) for(int _x = 1; _x <= 2*n; _x++)
    {
        _x == 2*n ? printf("%d\n", arr[_y][_x]) : printf("%d ", arr[_y][_x]);
    }
    return 0;
}