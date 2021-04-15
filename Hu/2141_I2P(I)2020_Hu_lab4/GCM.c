#include<stdio.h>
int main()
{
    int x, y, mult;
    scanf("%d%d", &x, &y);
    mult = y > x ? y : x;
    while(mult % x || mult % y) mult ++;
    printf("%d\n", mult);
}