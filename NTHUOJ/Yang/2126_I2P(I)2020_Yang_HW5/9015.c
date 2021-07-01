#include<stdio.h>
int main()
{
	char s[100005];
	while(scanf("%s", s)!=EOF)
	{
		int len = 0, ispalin = 1;
		for(int i = 0; s[i] != '\0'; i++) len++;
		for(int l = 0, r = len-1; l < r; l++, r--) if(s[l] != s[r])
		{
			ispalin = 0;
			break;
		}
		if(ispalin) printf("Yes\n");
		else printf("No\n");
	}
}