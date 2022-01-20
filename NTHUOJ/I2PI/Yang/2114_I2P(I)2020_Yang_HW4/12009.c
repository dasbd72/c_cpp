#include<stdio.h>
//Caesar salad
int main()
{
    char inp[4];
    int n;
    scanf("%s%d", inp, &n);
    for(int i = 0;i < 3; i++) inp[i] = (inp[i] - 'A' + n % 26 + 26) % 26 + 'A';
    printf("%s\n", inp);
}