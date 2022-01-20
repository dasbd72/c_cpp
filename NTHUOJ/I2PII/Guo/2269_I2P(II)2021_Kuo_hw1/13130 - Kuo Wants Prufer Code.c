// passed
#include<stdio.h>
#include<stdlib.h>
int main(){
    int N, V[5005], U[5005], cnt[5005]={};
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", V+i, U+i);
        cnt[V[i]]++, cnt[U[i]]++;
    }
    for(int t = 0; t < N-2; t++){
        int idx = 1;
        while(idx <= N){
            if(cnt[idx] == 1) break;
            idx++;
        }
        for(int i = 0, finished = 0; i < N-1 && !finished; i++){
            if(U[i] == idx) finished = 1;
            else if(V[i] == idx) finished = 1;

            if(finished){
                printf("%d ", V[i] == idx ? U[i] : V[i]);
                cnt[U[i]]--, cnt[V[i]]--;
                U[i] = V[i] = -1;
            }
        }
    }
    puts("");
}