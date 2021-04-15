#include<stdio.h>
#define ll unsigned long long int
ll stat[120]={1, 1, 1};
int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 3; i <= N; i++)
	{
		stat[i] = stat[i-1] + stat[i-3];
	}
	printf("%llu\n", stat[N]);
	return 0;
}