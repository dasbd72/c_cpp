#include<stdio.h>
#include<math.h>
char carpet[3000][3000]={0};
int n;
void sier(int size, int y, int x)
{
    //the minimum size of the block is 3
    if(size < 3) return;
    int block = size/3;
    //fill middle block
    for(int i = block + y; i < block*2 + y; i++) for(int j = block + x; j < block*2 + x; j++)
        carpet[i][j] = '#';
    //do the recursion to the rest 8 blocks
    for(int i = y; i <= block*2 + y; i+=block) for(int j = x; j <= block*2 + x; j+=block) 
        if(i != block || j != block) sier(block, i, j);
}
int main()
{
    scanf("%d", &n);
    int size = pow(3, n);
    //reset
    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
        carpet[i][j] = '.';

    sier(size, 0, 0);
    //print
    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) 
        j == size-1 ? printf("%c\n", carpet[i][j]) : printf("%c", carpet[i][j]);
    return 0;
}