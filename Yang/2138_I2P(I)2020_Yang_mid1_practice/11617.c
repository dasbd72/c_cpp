#include<stdio.h>
int main()
{
	int n, m, x, printed[200005]={}, oparr[100005]={}, idx = -1;
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d", &x);
		oparr[++idx] = x; // stack the numbers on
	}
	// because the number will only appear once, so if u printed it, don't print it again
	for(int i = idx; i >= 0; i--) if(!printed[ oparr[i] ])
	{
		printf("%d\n", oparr[i]);
		printed[ oparr[i] ] = 1;
	}
	for(int i = 1; i <= n; i++) if(!printed[i]) printf("%d\n", i);
	return 0;
}