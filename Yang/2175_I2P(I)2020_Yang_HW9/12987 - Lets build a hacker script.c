#include<stdio.h>
#include<string.h>
char S[22], P[22];
int Slen, Plen;
int set[22], haveAns = 0;

void find(int, int, int);

int main()
{
    scanf("%s%s", S, P);
    Slen = strlen(S), Plen = strlen(P);
    for(int i = 0; i < Slen; i++) set[i] = -1;
    find(0, 0, 1);
    if(!haveAns) printf("What the hack!?\n");
}
void find(int Si, int Pi, int cnt){
    if(Pi == Plen && Si == Slen){
        haveAns = 1;
        for(int i = 0, flag = 0; i < Slen; i++){
            if(i > 0 && set[i] && set[i-1] != set[i] && flag) printf(" ");
            if(set[i]){
                printf("%c", S[i]);
                flag = 1;
            }
        }
        printf("\n");
    }
    else if(Pi == Plen) return;
    else if(Si == Slen) return;
    else if(P[Pi] == '#') for(int i = 1; i <= Slen - Si; i++){
        for(int j = Si; j < Si+i; j++) set[j] = cnt;
        find(Si+i, Pi+1, cnt+1);
    }
    else if(P[Pi] == S[Si]){
        set[Si] = 0;
        find(Si+1, Pi+1, cnt);
    }
    else return;
}