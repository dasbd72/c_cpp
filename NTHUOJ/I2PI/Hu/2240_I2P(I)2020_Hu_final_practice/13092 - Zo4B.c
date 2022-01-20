#include<stdio.h>
#include<stdlib.h>
const int Y[]={-1,0,1,0}, X[]={0,1,0,-1};
int readEOF, board[6][6], moved[6][6];
void copy();
void print();
void solve();
void move_single(int r, int c, int d);
int main(){
    while(!readEOF){
        for(int r = 1; r <= 4; r++) for(int c = 1; c <= 4; c++) {
            if(scanf("%d", &board[r][c]) == EOF){
                readEOF = 1;
                r = c = 5;
            }
        }
        if(readEOF) break;
        solve();
    }
}
void copy(){
    for(int r = 1; r < 5; r++) for(int c = 1; c < 5; c++){
        moved[r][c] = board[r][c];
    }
}
void print(){
    int invalid = 1;
    for(int r = 1; r < 5; r++) for(int c = 1; c < 5; c++){
        if(moved[r][c] != board[r][c]){
            invalid = 0;
            r = c = 5;
        }
    }
    if(invalid) puts("Invalid");
    else for(int r = 1; r < 5; r++) for(int c = 1; c < 5; c++){
        printf("%d%c", moved[r][c], c==4?'\n':' ');
    }
    // puts("");
}
void solve(){
    copy();
    for(int c = 1; c < 5; c++) move_single(1, c, 2);
    print();
    copy();
    for(int c = 1; c < 5; c++) move_single(4, c, 0);
    print();
    copy();
    for(int r = 1; r < 5; r++) move_single(r, 1, 1);
    print();
    copy();
    for(int r = 1; r < 5; r++) move_single(r, 4, 3);
    print();
}
void move_single(int r, int c, int d){
    for(int i = 0; i < 4; i++){
        if(moved[r+Y[d] * i][c+X[d] * i] == 0) for(int j = i+1; j < 4; j++){
            if(moved[r+Y[d] * j][c+X[d] * j]){
                moved[r+Y[d] * i][c+X[d] * i] = moved[r+Y[d] * j][c+X[d] * j];
                moved[r+Y[d] * j][c+X[d] * j] = 0;
                i--;
                break;
            }
        }
        else{
            for(int j = i+1; j < 4; j++){
                if(moved[r+Y[d] * i][c+X[d] * i] == moved[r+Y[d] * j][c+X[d] * j]){
                    moved[r+Y[d] * i][c+X[d] * i] += moved[r+Y[d] * j][c+X[d] * j];
                    moved[r+Y[d] * j][c+X[d] * j] = 0;
                    break;
                }
                else if(moved[r+Y[d] * j][c+X[d] * j]) break;
            }
        }
    }
}