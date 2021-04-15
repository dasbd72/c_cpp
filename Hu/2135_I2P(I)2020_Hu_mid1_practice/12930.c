#include<stdio.h>
int main()
{
	int n, q;
	char s[1005], tmp[1005];
	scanf("%d %s %d", &n, s, &q);
	while(q--)
	{
		int a, b, sz;
		long long int numA = 0, numB = 0; //reset numA and numB
		scanf("%d%d%d", &a, &b, &sz);
		for(int i = a, j = b; i < a+sz; i++, j++) //because A and B are equally long, so i can do them together
		{
			// ex: 123 = 0 + 1 -> 1 * 10 + 2 -> 12 * 10 + 3
			numA *= 10;
			numA += s[i]-'0';
			
			numB *= 10;
			numB += s[j]-'0';

			// clear used s[i] s[j]
			s[i] = s[j] = 0;
		}
		printf("%lld\n", numA*numB);

		for(int i = 0, j = 0; i < n; i++, j++)
		{
			//if s[i] is used, skip it
			while(s[i] == 0) i++;
			tmp[j] = s[i];
		}
		//len become shorter
		n -= sz*2;

		//copy over the array
		for(int i = 0; i < n; i++) s[i] = tmp[i];
	}
	return 0;
}