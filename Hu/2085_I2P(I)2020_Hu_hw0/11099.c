#include<stdio.h>
int main(){
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);
    int tot = (X + Y + Z)/2;
    printf("%d %d %d\n", tot - Y, tot - Z, tot - X);
}