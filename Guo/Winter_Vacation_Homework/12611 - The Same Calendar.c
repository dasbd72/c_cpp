// 12611.c
#include <stdio.h>
int isleap(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100)) return 1;
    return 0;
}
int main(){
    int T, y, _y, prefix[200000]={}, day;
    for(int i = 1000; i < 100500; i++){
        prefix[i] = prefix[i-1];
        prefix[i] += isleap(i) ? 366 : 365;
    }
    for(scanf("%d", &T); T--; ){
        scanf("%d", &y);
        for(_y = y; ; _y++){
            day = prefix[_y] - prefix[y-1];
            if(day % 7 == 0 && isleap(_y+1) == isleap(y) ) break; 
        }
        printf("%d\n", _y+1);
    }
}