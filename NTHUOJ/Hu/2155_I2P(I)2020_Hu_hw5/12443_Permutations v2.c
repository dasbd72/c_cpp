#include<stdio.h>
#define MAXN 100
int N;
int arr[MAXN];
void permutation(int idx)
{
    //ending condition
    if(idx == N)
    {
        for(int i = 1; i <= N; i++) i == N ? printf("%d \n", arr[i]) : printf("%d ", arr[i]);
        return;
    }
    for(int i = idx; i <= N; i++)
    {
        int tmp1 = arr[i], tmp2;
        for(int j = 0; j <= i-idx; j++) 
        {
            tmp2 = arr[idx+j];
            arr[idx+j] = tmp1;
            tmp1 = tmp2;
        }
        permutation(idx+1);
        tmp1 = arr[idx];
        for(int j = i-idx; j >= 0; j--)
        {
            tmp2 = arr[idx + j];
            arr[idx+j] = tmp1;
            tmp1 = tmp2;
        }
    }
}
int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) arr[i] = i;
    permutation(1);
    return 0;
}