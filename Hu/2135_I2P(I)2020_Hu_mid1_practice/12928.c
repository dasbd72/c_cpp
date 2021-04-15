#include <stdio.h>
#define MAX_SIDE 150
int main()
{
	int n, m, q, a[MAX_SIDE][MAX_SIDE]={}, tmparr[MAX_SIDE][MAX_SIDE]={};
	int row, col;

	scanf("%d%d", &n, &m);
	row = n, col = m;

	for(int y = 0; y < n; y++) for(int x = 0; x < m; x++)
		scanf("%d", &a[y][x]);

	// turning over four times is useless
	scanf("%d", &q);
	q %= 4;

	while(q--)
	{
		//swap row and col
		row += col;
		col = row - col;
		row = row - col;

		//turn row and col
		for(int y = 0; y < row; y++) for(int x = 0; x < col; x++)
			tmparr[y][x] = a[col - x -1][y];

		//copy over
		for(int y = 0; y < row; y++) for(int x = 0; x < col; x++) a[y][x] = tmparr[y][x];
	}

	//print the array
	for(int y = 0; y < row; y++) for(int x = 0; x < col; x++)
		x == col-1 ? printf("%d\n", a[y][x]) : printf("%d ", a[y][x]);
	return 0;
}
/*
3 4
1 2 3 4
5 6 7 8
2 2 3 9
2
*/