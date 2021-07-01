// 12604.c
#include<stdio.h>
#include<stdlib.h>
int N, M, size;
int col2row[11][2]; // type 1:queen, 2:rook
// q:remainig queens, r:remaining rooks, pos:current column, returns the sum of ways
int ways(int q, int r, int pos){
    if(pos == size+1) return 1;

    int availible, sum = 0;
    for(int type = 1; type <= 2; type++){
        if(type == 1 && q == 0) continue;
        if(type == 2 && r == 0) continue;
        for(int row = 1; row <= size; row++){
            availible = 1;
            for(int col = 1; col < pos; col++){
                // check of is on same row, and if either of one is queen, check X way. 
                if(col2row[col][1] == row || ((type == 1 || col2row[col][0] == 1) && (col2row[col][1]+col == row+pos || col2row[col][1]-col == row-pos)))
                    availible = 0, col = pos;
            }
            if(availible){
                col2row[pos][0] = type;
                col2row[pos][1] = row;
                if(type == 1) sum += ways(q-1, r, pos+1);
                else sum += ways(q, r-1, pos+1);
            }
        }
    }
    return sum;
}
int main(){
    while(scanf("%d %d", &N, &M) != EOF){
        size = N + M;
        printf("%d\n", ways(N, M, 1));
    }
}