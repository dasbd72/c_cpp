#include<stdio.h>
#include<math.h>
int main()
{
	int N, primeFacCnt[101][101]={}; //save the prime factor count
	scanf("%d", &N);
	for(int i = 2; i <= N; i++) //do number i's Prime factorization
	{
		int num = i, primeFac = 2;
		while(num > 1)
		{
			if(primeFacCnt[num][0]) //if the remain number has been calculated, use the data
			{
				for(int j = 2; j <= num; j++) primeFacCnt[i][j] += primeFacCnt[num][j];
				num = 1;
			}
			else //else calculate
			{
				while(num % primeFac == 0)
				{
					num /= primeFac;
					primeFacCnt[i][primeFac]++;
				}
				primeFac++;
			}
		}
		primeFacCnt[i][0] = 1; //note that this number i have been calculated
	}
	long long ans = 1;
	for(int j = 2; j <= N; j++) //count the factors of all number
	{
		int powers = 1;
		for(int i = 2; i <= N; i++) powers += primeFacCnt[i][j]; 
		ans *= powers;
	}
	printf("%lld", ans);
}