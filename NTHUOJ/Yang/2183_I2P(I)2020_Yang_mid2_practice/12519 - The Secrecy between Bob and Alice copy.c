#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pair{
    int fr;
    char *s;
} S[5005];
int N, tot = 0;
char P[5005];
int cmp(const char *a, const char *b){
    if(strlen(a) != strlen(b)) return 0;
    int au[26]={}, bu[26]={};
    for(int i = 0; a[i] != 0; i++){
        if(!au[a[i]-'a']) au[a[i]-'a'] = i;
        if(!bu[b[i]-'a']) bu[b[i]-'a'] = i;
        if(au[a[i]-'a'] != bu[b[i]-'a']) return 0;
    }
    return 1;
}
int main(){
    scanf("%d %s", &N, P);
    for(int i = 0; i < N; i++) {
        S[i].fr = 0, S[i].s = (char*)malloc(sizeof(char)*5005);
        scanf("%s", S[i].s);
    }
    for(int i = 0; i < N; i++) if(cmp(P, S[i].s)) {
        tot++, S[i].fr++;
        for(int j = i+1; j < N; j++){
            if(strcmp(S[i].s, S[j].s) == 0) S[i].fr++, i = j==N-1 ? j : i;
            else{
                i = j-1;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N-i-1; j++) {
        int flag = 0;
        if(S[j].fr < S[j+1].fr) flag = 1;
        // else if(S[j].fr == S[j+1].fr && strcmp(S[j].s, S[j+1].s)>0) flag = 1;
        if(flag){
            int frtmp = S[i].fr; char *stmp = S[i].s;
            S[i].fr = S[j].fr, S[i].s = S[j].s;
            S[j].fr = frtmp, S[j].s = stmp;
        }
    }
    
    printf("%d\n", tot);
    for(int i = 0; i < N; i++){
        if(S[i].fr) printf("%s %d\n", S[i].s, S[i].fr);
        free(S[i].s);
    }
}
/*
7 the
opq
fiv
fiv
fiv
fivqv
oaq
six

*/