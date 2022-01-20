#include<stdio.h>
int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		char a[1005], b[1005];
		int acnt[30]={}, bcnt[30]={}, iscorrect = 1;
		scanf("%s %s", a, b);
		for(int i = 0; a[i]!='\0'; i++) acnt[a[i]-'a']++;
		for(int i = 0; b[i]!='\0'; i++) bcnt[b[i]-'a']++;
		for(int i = 0; i < 26; i++) if(acnt[i] != bcnt[i])
		{
			iscorrect = 0;
			break;
		}
		if(iscorrect) printf("YES\n");
		else printf("NO\n");
	}
}