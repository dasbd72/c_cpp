#include<stdio.h>
int sodoku[9][9]={};
int ans[9][9]={};
int check_row(int y, int all)
{
	int numcnt[10]={};
	for(int col = 0; col < 9; col++) numcnt[ sodoku[y][col] ]++;
	if(!all) 
	{
		for(int i = 1; i <= 9; i++) if(numcnt[i] > 1) return 0;
	}
	else for(int i = 1; i <= 9; i++) if(numcnt[i] != 1) return 0;
	return 1;
}
int check_col(int x, int all)
{
	int numcnt[10]={};
	for(int row = 0; row < 9; row++) numcnt[ sodoku[row][x] ]++;
	if(!all) 
	{
		for(int i = 1; i <= 9; i++) if(numcnt[i] > 1) return 0;
	}
	else for(int i = 1; i <= 9; i++) if(numcnt[i] != 1) return 0;
	return 1;
}
int check_block(int y, int x, int all)
{
	int numcnt[10]={};
	for(int row = y - y % 3; row < y - y % 3 + 3; row++) for(int col = x - x % 3; col < x - x % 3 + 3; col++)
		numcnt[ sodoku[row][col] ]++;
	if(!all)
	{
		for(int i = 1; i <= 9; i++) if(numcnt[i] > 1) return 0;
	}
	else for(int i = 1; i <= 9; i++) if(numcnt[i] != 1) return 0;
	// printf("block clear %d %d\n", y, x);
	return 1;
}
int check_point(int y, int x)
{
	if(!check_row(y, 0) || !check_col(x, 0) || !check_block(y, x, 0)) return 0;
	return 1;
}
int check_all()
{
	for(int i = 0; i < 9; i++) if(!check_row(i, 1)) return 0;
	for(int i = 0; i < 9; i++) if(!check_col(i, 1)) return 0;
	for(int i = 0; i < 9; i+=3) for(int j = 0; j < 9; j+=3) if(!check_block(i, j, 1)) return 0;
	return 1;
}
void copy_ans()
{
	for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++) ans[i][j] = sodoku[i][j];
}
int solve(int y, int x)
{
	if(sodoku[y][x] != -1)
	{
		int found = 0;
		for(int row = y; row < 9 && !found; row++) for(int col = row == y ? x + 1 : 0; col < 9 && !found; col++)
		{
			if(sodoku[row][col] == -1) y = row, x = col, found = 1;
			else if(row == 8 && col == 8 && check_all())
			{
				copy_ans();
				return 1;
			}
		}
	}
	for(int i = 1; i <= 9; i++)
	{
		sodoku[y][x] = i;
		if(check_point(y, x))
		{
			if(y == 8 && x == 8)
			{
				copy_ans();
				return 1;
			}
			else if(solve(y, x)) return 1;
		}
	}
	sodoku[y][x] = -1;
	return 0;
}
int main()
{
	char inp[20];
	int needsolve = 0;
	for(int i = 0; i < 9; i++)
	{
		if(i % 3 == 0) scanf("%s", inp);
		scanf("%s", inp);

		for(int j = 0, x = 0; j < 12; j++, x++)
		{
			if(inp[j] == '|') j++;
			if(inp[j] == 'x') sodoku[i][x] = -1, needsolve = 1;
			else sodoku[i][x] = inp[j]-'0';
		}
		if(i == 8) scanf("%s", inp);
	}
	if(needsolve)
	{
		if(solve(0, 0)) printf("question, valid\n");
		else printf("question, invalid\n");
	}
	else 
	{
		if(check_all()) printf("solution, valid\n");
		else printf("solution, invalid\n");
	}
	for(int row = 0; row < 9; row++) 
		for(int col = 0; col < 9; col++) col == 8 ? printf("%2d\n", sodoku[row][col]) : printf("%2d ", sodoku[row][col]);
	return 0;
}