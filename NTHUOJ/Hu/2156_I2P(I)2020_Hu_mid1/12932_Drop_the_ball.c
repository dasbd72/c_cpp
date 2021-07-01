#include<stdio.h>
int main()
{
	char arr[505][505]={{0}};
    int row, col, q, x;
    int left, right, stuck; 
    scanf("%d%d", &row, &col);
    for(int i = 0; i < row; i++) scanf("%s", arr[i]+1);
    scanf("%d", &q);
    while(q--)
    {
        left = right = stuck = 0; 
        scanf("%d", &x);
        for(int i = 0; i < row && !stuck && !right && !left; i++)
        {
            if(arr[i][x] == '/' && arr[i][x-1] == '/') x--;
            else if(arr[i][x] == '\\' && arr[i][x+1] == '\\') x++;
            else if(arr[i][x] == '/' && arr[i][x-1] == '\\') stuck = 1;
            else if(arr[i][x] == '\\' && arr[i][x+1] == '/') stuck = 1;
            else if(arr[i][x] == '/') left = 1;
            else if(arr[i][x] == '\\') right = 1;
        }
        if(stuck) printf("Stuck QQ\n");
        else if(left) printf("Left!\n");
        else if(right) printf("Right!\n");
        else printf("Position: %d\n", x);
    }
	return 0;
}