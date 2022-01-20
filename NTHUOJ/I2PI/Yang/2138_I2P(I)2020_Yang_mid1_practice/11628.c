#include<stdio.h>
char spiral[5001][5001];
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int _N = N, y = 0, x = -1;
		for(int row = 0; row < N; row++)
		for(int col = 0; col < N; col++)
		{
			spiral[row][col] = 0;
		}
		while(_N > 0)
		{
			for(int i = 0; i < _N; i++) spiral[y][++x] = 1;
			_N--;
			for(int i = 0; i < _N; i++) spiral[++y][x] = 1;
			_N--;
			for(int i = 0; i < _N; i++) spiral[y][--x] = 1;
			_N--;
			for(int i = 0; i < _N; i++) spiral[--y][x] = 1;
			_N--;
		}
		for(int row = 0; row < N; row++)
		for(int col = 0; col < N; col++)
		{
			if(spiral[row][col] == 1) printf("#");
			else printf(" ");
			if(col == N-1) printf("\n");
		}
	}
}