// Dont use double for loop or you will get TLE
#include<stdio.h>
int main()
{
	int N, cnt[10005]={};
	long long ans = 0, tmp;
	scanf("%d", &N);
	//count the number's appearance into cnt[num]
	for(int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		cnt[x]++;
	}
	//ans += C(cnt[i], 2)
	for(int i = 0; i <= 10000; i++)
	{
		// you need to either seperate the calculation or set cnt to long long, or the process of calculation overflows 
		tmp = cnt[i];
		tmp *= cnt[i]-1;
		tmp /= 2;
		ans += tmp;
	}
	printf("%lld\n",ans);
	return 0;
}