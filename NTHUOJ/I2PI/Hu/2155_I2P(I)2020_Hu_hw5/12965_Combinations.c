#include<stdio.h>
int M, N, arr[30]={0}, chosen[30]={0};
void combination(int idx, int cnt)
{
    if(cnt == 0)
    {
        for(int i = 0; i < N; i++) if(chosen[i]) 
            chosen[i] == 1 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
        return;
    }
    if(idx == N) return;
    
    for(int i = idx; i < N; i++)
    {
        chosen[i] = cnt;
        combination(i + 1, cnt-1);
        chosen[i] = 0;
    }
}
int main()
{
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    combination(0, M);
}