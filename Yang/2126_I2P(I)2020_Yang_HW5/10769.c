#include<stdio.h>
int main()
{
	int N, arr[25][25]={};
	scanf("%d", &N);
	for(int row = 0; row < N; row++)
		for(int col = 0; col < N; col++)
			scanf("%d", &arr[row][col]);
	int yHead = 0, xHead = 0, layer = 0;
	while(layer++ < 2*N-1)
	{
		int y = yHead, x = xHead;
		for(int i = 0; i < layer && i < 2*N-layer; i++)
		{
			i == layer-1 || i == 2*N-layer-1 ? printf("%d\n", arr[y][x]) : printf("%d ", arr[y][x]);
			i == layer-1 || i == 2*N-layer-1 ? 0 : y--, x++;
		}
		if(layer < N) yHead++;
		else xHead++;
	}
}