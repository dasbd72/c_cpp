#include<stdio.h>
#include<string.h>
int main()
{
	char inp[105]={};
	int started = 0, hasmeaning = 1, ans[105]={};
	int idx;
	scanf("%s", inp);

	for(int i = strlen(inp) - 1; i >= 0; i--, idx++)
	{
		//if appeared one number which is not '0' then know it has started, and started to count idx from 0
		if(!started && inp[i] != '0')
		{
			started = 1;
			idx = 0;
		}
		//if appeared 2 3 4 5 7 the number has no meaning, else save the turned number
		if(started) switch(inp[i]) 
		{
			case '1':
				ans[idx] = 1;
				break;
			case '6':
				ans[idx] = 9;
				break;
			case '8':
				ans[idx] = 8;
				break;
			case '9':
				ans[idx] = 6;
				break;
			case '0':
				ans[idx] = 0;
				break;
			default:
				hasmeaning = 0;
				break;

		}
	}
	if(!hasmeaning) printf("No\n");
	else if(hasmeaning && !started) printf("0\n");
	else for(int i = 0; i < idx; i++)
		i == idx -1 ? printf("%d\n", ans[i]) : printf("%d", ans[i]);
	return 0;
}