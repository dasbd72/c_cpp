#include <stdio.h>
#define MAXN 1000005
int arr[MAXN];
long long int prefixSum[MAXN]; // if you dont do this, you'll get TLE
int main()
{
	int N, M; // 10 <= N <= 1000000
	long long int sum = 0; // sum <= 1000000 * 100000

	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		// prefixSum i = arr[1] + ... + arr[i]
		scanf("%d", &arr[i]);
		sum += arr[i];
		prefixSum[i] = sum;
	}
	scanf("%d", &M);
	while(M--) // run M times
	{
		int L, R;
		scanf("%d%d", &L, &R);
		// ans = prefixSum[R] - prefixSum[L-1]
		printf("%lld\n", prefixSum[R] - prefixSum[L-1]);
	}
	return 0;
}