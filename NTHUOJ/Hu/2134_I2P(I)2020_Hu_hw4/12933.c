#include<stdio.h>
int main()
{
	int row, col;
	short arr[1005][1005]={};
	scanf("%d %d", &row, &col);
	for(int y = 0; y < row; y++) for(int x = 0; x < col; x++) scanf("%d", &arr[y][x]);
	for(int x = 0; x < col; x++) for(int y = 0; y < row; y++) y == row-1 ? printf("%d\n", arr[y][x]) : printf("%d ", arr[y][x]);
	return 0;
}