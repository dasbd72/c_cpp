#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;
int map[MAX][MAX], row, col;
int main(){
    int y, x, _case = 1;
    while(cin >> row >> col){
        if(row == -1 && col == -1)break;
        memset(map, 0, sizeof(map));
        while(cin >> y >> x){
            if(y == 0 && x == 0) break;
            else map[y][x] = 1;
        }
        
    }
}