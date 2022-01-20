#include<stdio.h>
int main()
{
	int n, m, q, maparr[505][505]={{0}};
	char inp[505];
	scanf("%d%d", &n, &m);
	for(int y = 1; y <= n; y++) for(int x = 1; x <= m; x++) maparr[y][x] = -1; // reset map
	for(int y = 1; y <= n; y++)
	{
		scanf("%s", inp);
		for(int x = 1; x <= m; x++)
		{
			if(x == 1 && inp[x-1] == '/') maparr[y][x] = 0;
			if(x == m) { if(inp[x-1] == '\\') maparr[y][x] = x+1; }

			if(inp[x-1] == '/' && inp[x] == '/') maparr[y][x+1] = x;
			else if(inp[x-1] == '\\' && inp[x] == '\\') maparr[y][x] = x+1;
		}
	}
	//for(int y = 1; y <= n; y++) for(int x = 1; x <= m; x++) x == m ? printf("%2d\n", maparr[y][x]) : printf("%2d ", maparr[y][x]);
	scanf("%d", &q);
	while(q--)
	{
		int i, y = 1;
		scanf("%d", &i);
		while(y <= n)
		{
			if(y == n && maparr[y][i] != -1)
			{
				printf("Position: %d\n", maparr[y][i]);
				break;
			}
			else if(maparr[y][i] == 0)
			{
				printf("Left!\n");
				break;
			}
			else if(maparr[y][i] == m+1)
			{
				printf("Right!\n");
				break;
			}
			else if(maparr[y][i] == -1)
			{
				printf("Stuck QQ\n");
				break;
			}
			else i = maparr[y][i];
			y++;
		}
	}
	return 0;
}
/*
5 6
////\\
/\\\\\
//\\\\
\\\\\/
\\////
6
1
2
3
4
5
6
*/