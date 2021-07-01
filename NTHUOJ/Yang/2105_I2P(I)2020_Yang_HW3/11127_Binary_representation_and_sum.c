#include<stdio.h>
int main(){
    int N, carries=0, binary[20] = {}, i = 0;
    int isNotEnd = 1;
    scanf("%d", &N); //input
    N++;
    //turn into binary and count
    while(N){ 
        binary[i++] = N%2;
        //計算進位數量
        if(isNotEnd){ 
            if(N%2 == 0) carries++;
            else isNotEnd = 0;
        }
        N /= 2;
    }
    while(i){
        i--;
        printf("%d", binary[i]);
    }
    printf(" %d", carries);
    return 0;
}