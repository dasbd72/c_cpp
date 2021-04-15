#include<stdio.h>
#include<string.h>
int q, N, K, arr[12];
int set[12], availible;
void solve(int,int,int,int,int);
int main()
{
    for(scanf("%d", &q); q--; ){
        scanf("%d%d", &N, &K);
        for(int i = 0; i < N; i++) scanf("%d", arr+i);
        //reset the status
        for(int i = 0; i < N; i++) set[i] = 0;
        availible = 0;
        solve(0, 1, 0, 0, 0);
        printf("%s\n", availible ? "True": "False");
    }
    return 0;
}
/*
pos:curremt pos
setidx:the index of the current set
pickcnt:count how many numbers have been chosen(used to see if you have picked)
cursum:current sum of the set
cmpsum:the sum of the first set
*/
void solve(int pos, int setidx, int pickcnt, int cursum, int cmpsum){
    if(pos == N){
        if(pickcnt == 0) return;
        else if(setidx == 1) solve(0, setidx+1, 0, 0, cursum);
        else if(cursum != cmpsum) return;
        else if(setidx < K) solve(0, setidx+1, 0, 0, cmpsum);
        else if(setidx == K){
            for(int i = 0; i < N; i++) if(set[i] == 0) return;
            availible = 1;
        }
        return;
    }
    solve(pos+1, setidx, pickcnt, cursum, cmpsum);
    if(!set[pos]){
        set[pos] = setidx;
        solve(pos+1, setidx, pickcnt+1, cursum+arr[pos], cmpsum);
        set[pos] = 0;
    }
    return;
}