#include<stdio.h>
int q, N, K, arr[12];
int totsum, partsum, par[6], flag;
void solve(int);
int check();
int main()
{
    // input
    for(scanf("%d", &q); q--; ){
        flag = totsum = 0;
        scanf("%d%d", &N, &K);
        for(int i = 0; i < N; i++){
            scanf("%d", arr+i);
            totsum += arr[i];
        }
        partsum = totsum / K;
        solve(0);
        printf("%s\n", flag == 1 ? "True" : "False");
    }
}
void solve(int pos){
    if(pos == N){
        if(check()) flag = 1;
    }
    else for(int i = 0; i < K; i++){
        par[i] += arr[pos];
        solve(pos+1);
        par[i] -= arr[pos];
    }
    return;
}
int check(){
    for(int i = 0; i < K; i++) if(par[i] != partsum) return 0;
    return 1;
}