#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N, f[5005], tot;
char S[5005][5005], P[5005];
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
    for(int i = 0; i < N; i++) scanf("%s", S[i]);
    for(int i = 0, cnt; i < N; i++) if(cmp(P, S[i])){
        tot++, cnt = 1;
        while(i + cnt < N && strcmp(S[i], S[i+cnt]) == 0) cnt++;
        f[i] = cnt, i += cnt-1;
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N-i-1; j++){
        int flag = 0;
        if(f[j] < f[j+1]) flag = 1;
        else if(f[j] == f[j+1] && strcmp(S[j], S[j+1]) > 0) flag = 1;
        if(flag){
            int _f; char _s[5005];
            _f = f[j]; f[j] = f[j+1]; f[j+1] = _f;
            strcpy(_s, S[j]); strcpy(S[j], S[j+1]); strcpy(S[j+1], _s);  
        }
    }
    printf("%d\n", tot);
    for(int i = 0; i < N; i++)if(f[i]){
        printf("%s %d\n", S[i], f[i]);
    }
}
/*
7 the
aaa
fiv
fiv
opq
oaq
six
six

*/