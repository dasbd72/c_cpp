// 12145.c
#include<stdio.h>
int main(){
	int n, unavailible=0;
	int cnt[30]={};
	char c;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%c", &c);
		if(c == '\n') scanf("%c", &c);
		cnt[c-'a']++;
	}
	for(int i = 0; i < 26; i ++)
		if(cnt[i] == 1) unavailible++;
	(unavailible == n && n != 1) ? printf("Different makes perfect\n") : printf("I'm the god of Knuckles!\n");
	return 0;
}