// 12614.c
#include <stdio.h>
int main(){
    int N, M, A[1005], C[1005];
    int iA, iC, ans;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", C+i);
    for(int i = 0; i < M; i++) scanf("%d", A+i);
    for(iA = iC = ans = 0; iC < N && iA < M; iC++)
        if(C[iC] <= A[iA]) ans++, iA++;
    printf("%d\n", ans);
}