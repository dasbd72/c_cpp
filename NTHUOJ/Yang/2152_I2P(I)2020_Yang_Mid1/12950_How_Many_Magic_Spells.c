#include<stdio.h>
#include<string.h>
int optimize[2005][2005]={0};
int T, Q, L, R;
char A[2005], B[2005];
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf( "%s %s %d", A, B, &Q );
        int lenA = strlen(A), lenB = strlen(B);
        for(int i = 0; i <= lenA; i++) for(int j = 0; j < lenA; j++) optimize[i][j] = 0;
        for(int i = lenA-1; i >= 0; i--)
        {
            if(A[i] == B[0])
            {
                int j = 0;
                while(A[i+j] == B[j] && j < lenB && i + j < lenA) optimize[i][i+j]++, j++;
            }
            for(int k = lenA-1; k >= i; k--) optimize[i][k] += optimize[i+1][k];
        }
        while(Q--)
        {
            scanf("%d %d", &L, &R);
            printf("%d\n", optimize[L][R] + 1);
        }
    }
    return 0;
}