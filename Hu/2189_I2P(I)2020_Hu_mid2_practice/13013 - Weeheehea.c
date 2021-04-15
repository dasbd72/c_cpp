/*
Solution: turn the binary into decimal numbers
cuz every combination of binary has a unique decimal value
and for every combination of binary numbers, save the pair of (num, xpos), which xpos is the position of x
p.s. Don't try to seperate the string into two part cuz oj won't let u declare array with size of 1024*1024
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXBIN 2050
char s[12];
int N;
int xpos, n1, ans = 0, stat[MAXBIN][10]={};
int main()
{
    scanf("%d", &N);
    for(int n = 0; n < N; n++){
        scanf("%s", s);
        n1 = 0;
        for(int i = 0; i < 10; i++) if(s[i] == 'x') xpos = i;
        for(int i = 0; i < 10; i++){
            if(i == xpos) i++;
            n1 = n1 << 1;
            n1 += s[i] == '1' ?  1 : 0;
        }
        stat[n1][xpos]++;
    }
    for(int i = 0; i < MAXBIN; i++) for(int j = 0; j < 10; j++) if(stat[i][j]) ans++;
    printf("%d\n", ans);
}