#include<stdio.h>
#include<stdlib.h>

int main()
{
	int R, C, arr[20][20]={}, max = 0, posmax[2]={}, min = 0x7fffffff, posmin[2]={};
	scanf("%d%d", &R, &C);
	for(int row = 0; row < R; row++) for(int col = 0; col < C; col++)
	{
		scanf("%d", &arr[row][col]);
		if(arr[row][col] > max)
		{
			max = arr[row][col];
			posmax[0] = row;
			posmax[1] = col;
		}
		if(arr[row][col] < min)
		{
			min = arr[row][col];
			posmin[0] = row;
			posmin[1] = col;
		}
	}
	printf("%d %d", abs(posmax[0]-posmin[0]) + abs(posmax[1]-posmin[1]), max-min);
}