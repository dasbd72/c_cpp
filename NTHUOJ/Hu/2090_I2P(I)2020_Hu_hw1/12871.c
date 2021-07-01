#include<stdio.h>
int main(){
    int D, count = 0;
    char C;

    scanf("%c%d", &C, &D);
    count += C;
    if(C <= 'Z' && C >= 'A'){
        count += -'A' + 'a' - D;
        if(count > 'z') count -= 26;
        else if(count < 'a') count += 26;
    }else{
        count += -'a' + 'A' - D;
        if(count > 'Z') count -= 26;
        else if(count < 'A') count += 26;
    }

    printf("%c\n", count);
    return 0;
}