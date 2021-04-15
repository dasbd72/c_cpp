#include<stdio.h>
int q, N, K;
char save[1100000];
// return 1 if you have one posibility to win or 0 if impossible to win
// use set with binary calculate to represent if the ith one is selected
int find(int set, int sum){
    if(sum >= K) return save[set] = 0;
    if(save[set] != -1) return save[set];
    int next;
    for(int i = 0; i < N; i++)if(!(set & (1 << i))){
        next = find(set | (1 << i), sum+i+1);
        if(next == 0)return save[set] = 1;
    }
    return save[set] = 0;
}
int main(){
    for(scanf("%d",&q); q--;){
        scanf("%d%d", &N, &K);
        for(int i = 0; i < (1 << N); i++) save[i] = -1;
        printf("%s\n", find(0, 0) ? "True" : "False");
    }
    return 0;
}