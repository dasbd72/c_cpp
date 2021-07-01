// pass
#include<stdio.h>
#include<string.h>
#define MAXN 1010
int main(){
    char S[MAXN], P[MAXN];
    int lenS, lenP;
    int q, a, b;
    int prefix[MAXN], ans, tmp;
    while(scanf("%s %s", S+1, P+1) != EOF){
        prefix[0] = 0;
        lenS = strlen(S+1), lenP = strlen(P+1);
        ans = 0;
        for(int i = 1; i <= lenS; i++){
            prefix[i] = prefix[i-1];
            if(i <= lenS - lenP + 1) for(int j = 1; j <= lenP; j++){
                if(S[i+j-1] != P[j]) break;
                else if(j == lenP) prefix[i]++;
            }
        }
        for(scanf("%d", &q); q--; ){
            scanf("%d %d", &a, &b);
            if(b < lenP) continue;
            tmp = prefix[b-lenP+1] - prefix[a-1];
            if(tmp > ans) ans = tmp;
        }
        printf("%d\n", ans);
    }
}