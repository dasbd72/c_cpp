#include<stdio.h>
#include<stdlib.h>
int main(){
    int cnt[5005]={}; 
    int V[5005], U[5005], N;
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        scanf("%d %d", V+i, U+i);
        cnt[V[i]]++;
        cnt[U[i]]++;
    }
    for(int round = 1; round <= N-2; round++){
        for(int idx = 1; idx <= N; idx++){
            if(cnt[idx] != 1) continue;
            else {
                for(int j = 1; j < N; j++){
                    if(V[j] != idx && U[j] != idx) continue;
                    if(V[j] == idx){
                        printf("%d ", U[j]);
                        cnt[V[j]] --;
                        cnt[U[j]] --;
                        V[j] = U[j] = 0;
                    }
                    else if(U[j] == idx){
                        printf("%d ", V[j]);
                        cnt[V[j]] --;
                        cnt[U[j]] --;
                        V[j] = U[j] = 0;
                    }
                }
                break;
            }
        }
    }
    puts("");
}