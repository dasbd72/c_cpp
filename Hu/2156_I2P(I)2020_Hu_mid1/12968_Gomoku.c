#include<stdio.h>
#define X 1
#define Y 0
const int dy[]={1, 1, 0, -1, -1, -1, 0, 1}, dx[]={0, 1, 1, 1, 0, -1, -1, -1}; // 8 dirextions to add of y and x, from up and clockwise
char board[17][17];
int have_link(int y, int x, char c)
{
    int dl[8] = {{0}};
    for(int i = 0; i < 7; i++) // run 8 directions
    {
        int ty = y, tx = x;
        while(board[ty + dy[i]][tx + dx[i]] == c) dl[i]++;
    }
    for(int i = 0; i < 4; i++) if(dl[i] + dl[i+4] >= 4) return 1;
    return 0;
}
int main()
{
    int q, white, black;
    scanf("%d", &q);
    while(q--)
    {
        white = black = 0;
        for(int i = 1; i <= 15; i++) scanf("%s", board[i]+1);
        for(int i = 1; i <= 15; i++) for(int j = 1; j <= 15; j++)
        {
            if(board[i][j] == 'b' && !black) if(have_link(i, j, 'b')) black = 1;
            if(board[i][j] == 'w' && !white) if(have_link(i, j, 'w')) white = 1;
        }
        if(black == white) printf("none\n");
        else if(black) printf("black\n");
        else if(white) printf("white\n");
    }
    return 0;
}