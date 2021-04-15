#include<stdio.h>
int main()
{
	int x, y, divisor;
	scanf("%d%d", &x, &y);
	divisor = x <= y ? x : y;
	while(divisor >= 1)
	{
		if(x % divisor == 0 && y % divisor == 0) break;
		divisor --;
	}
	printf("%d\n", divisor);
	return 0;
}