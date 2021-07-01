#include<stdio.h>
//Longest Row Vector
int main()
{
	printf("start\n");
    int m, n, K;
    short arr[1005][1005];
    scanf("%d %d %d", &m, &n, &K);
	// read input
    for(int row = 0; row < m; row++)
    for(int col = 0; col < n; col++)
    {
        scanf("%d", &arr[row][col]);
    }
	// read tasks
    while(K--)
    {
    	int cmd, i, j;
    	scanf("%d%d%d", &cmd, &i, &j);
    	if(cmd == 0)for(int col = 0; col < n; col++)
    	{
			//swap
			arr[i][col] += arr[j][col];
			arr[j][col] = arr[i][col] - arr[j][col];
			arr[i][col] = arr[i][col] - arr[j][col];
    	}
    	else for(int col = 0; col < n; col++) arr[i][col] += arr[j][col];
    }

    int max = 0, rowidx;
    for(int row = 0, tmp = 0; row < m; row++)
    {
    	for(int col = 0; col < n; col++)
    	{
			//count sum of square
    		tmp += arr[row][col] * arr[row][col];
    	}
    	if(tmp > max)
    	{
			//replace max and rowidx to the bigger one
    		max = tmp;
    		rowidx = row;
    	}
    }
    for(int col = 0; col < n; col++)
    {
		//output answer
    	col == n-1 ? printf("%d\n", arr[rowidx][col]) : printf("%d ", arr[rowidx][col]);
    }
    return 0;
}