#include<stdio.h>
#define MAXN 200
int main()
{
	char inpnum[2][MAXN];
	int numlen[2], ans[MAXN]={}, A = 0, B = 1;
	scanf("%d%s%d%s", &numlen[A], inpnum[A], &numlen[B], inpnum[B]);

	if(numlen[A] < numlen[B]) A = 1, B = 0;

	for(int i = 0; i < numlen[A]; i++)
	{
		ans[i] += inpnum[A][numlen[A]-i-1] - '0';
		if(i < numlen[B]) ans[i] += inpnum[B][numlen[B]-i-1] - '0';
		if(ans[i] > 9)
		{
			ans[i] -= 10;
			ans[i+1] ++;
		}
	}
	for(int i = ans[numlen[A]] ? numlen[A] : numlen[A]-1; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}
}