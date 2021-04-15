#include<stdio.h>
int main()
{
	int A = 0, B = 1, inversed = 0;
	int numlen[2]={}, bignum[2][110]={};
	char numstr[2][110];
	scanf("%d %s %d %s", &numlen[A], numstr[A], &numlen[B], numstr[B]);
	//turn string into array of num
	for(int j = 0; j < numlen[A]; j++) bignum[A][j] = numstr[A][numlen[A] - j - 1] - '0';
	for(int j = 0; j < numlen[B]; j++) bignum[B][j] = numstr[B][numlen[B] - j - 1] - '0';

	if(numlen[A] < numlen[B]) A = 1, B = 0, inversed = 1;
	else if(numlen[A] == numlen[B]) for(int idxCur = numlen[0]-1; idxCur >= 0; idxCur--)
	{
		//added here
		if(bignum[A][idxCur] > bignum[B][idxCur]) break;
		else if(bignum[A][idxCur] < bignum[B][idxCur]) 
		{
			A = 1, B = 0, inversed = 1;
			break;
		}
	}
	
	for(int i = 0; i < numlen[A]; i++)
	{
		bignum[A][i] -= bignum[B][i];
		if(bignum[A][i] < 0) bignum[A][i] += 10, bignum[A][i+1]--;
	}

	if(inversed) printf("-");
	int idx = numlen[A]-1;
	while(bignum[A][idx] == 0) idx--;
	if(idx < 0) printf("0");
	else while(idx >= 0) printf("%d", bignum[A][idx--]);

	return 0;
}