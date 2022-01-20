#include<stdio.h>
#define MAXN 505
int N, Q, U, V, X, K ,M, A1, A2;
int edge[MAXN][MAXN];
int path[MAXN][MAXN];
int oneedge[MAXN][MAXN];
int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; i++) for(int j = 0 ; j < N; j++) path[i][j] = 0x7FFFFFF;
    for(int i = 0; i < N-1; i++){
        scanf("%d %d %d", &U, &V, &X);
        edge[U][V] = edge[V][U] = 1;
        path[U][V] = path[V][U] = 1;
        oneedge[U][V] = oneedge[V][U] = X;
    }

    for(int t = 1; t <= 2; t++){
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(path[i][j]){
                    for(int k = 0; k < N; k++){
                        if(k != i && path[i][k] > path[j][k] + path[i][j]){
                            path[i][k] = path[k][i] = path[j][k] + path[i][j];
                            oneedge[i][k] = oneedge[k][i] = oneedge[j][k] + oneedge[i][j];
                        }
                    }
                }
            }
        }
    }
    while(Q--){
        int ans = 0;
        scanf("%d %d", &K, &M);
        for(int i = 0; i < K; i++){
            A1 = A2;
            scanf("%d", &A2);
            if(i != 0) ans += oneedge[A1][A2];
        }
        if(ans >= M) puts("YES");
        else puts("NO");
    }
}