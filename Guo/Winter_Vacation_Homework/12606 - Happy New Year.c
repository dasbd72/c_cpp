// 12606.c
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    int x = *(int*)a, y = *(int*)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}
int main(){
    int N, X[200005], ans;
    scanf("%d", &N);
    for(int i = 0; i <= N; i++) scanf("%d", X+i);
    qsort(X+1, N, sizeof(int), cmp);
    if(X[0] <= X[1]) ans = X[N] - X[0];
    else if(X[0] >= X[N]) ans = X[0] - X[1];
    else ans = X[N] - X[1];
    printf("%d\n", ans * 2);
}