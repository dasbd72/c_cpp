// you need to do optimize to this problem
#include<stdio.h>
int cont_idx[1000005]={}; // used to save the end index of the continuous number
/*
ex:
idx      : 0 1 2 3 4 5 6 7 
num      : 1 1 1 2 2 3 5 6
cont_idx : 2 2 2 4 4 5 6 7
*/
int main()
{
	int N, Q;
	short s[1000005]={};
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++) scanf("%d", &s[i]);
	for(int i = N-1, tmpidx = N-1; i >= 0; i--)
	{
		if(s[i] != s[tmpidx]) tmpidx = i;
		cont_idx[i] = tmpidx;
	}
	while(Q--)
	{
		int L, R, appeared[50]={}, cnt = 0;
		scanf("%d%d", &L, &R);
		for(int i = L; i <= R; i++) 
		{
			if(!appeared[s[i]])	cnt++,appeared[s[i]] = 1;
			i = cont_idx[i];
		}
		printf("%d\n", cnt);
	}
}