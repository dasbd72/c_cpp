// passed
#include<stdio.h>
#define _MAXBIN 32
void int_to_bit(int num){
    for(int i = 31; i >=0; i--){
        printf("%d", (num >> i) & 1 ? 1 : 0);
    }
}
int main()
{
    float numfloat;
    int n = sizeof(float) / sizeof(int);
    while(scanf("%f", &numfloat) != EOF){
        int *ptr = (int *)&numfloat;
        for(int i = 0; i < n; i++){
            int_to_bit(*(ptr+i));
        }
        printf("\n");
    }
}