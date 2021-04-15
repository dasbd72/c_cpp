#include<stdio.h>
int main(void)
{
    int n,m,t[200],T,i,a,b;
    char c[200]={'-'};



    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d %d",&n,&m,&t[i]);
        //printf("%d %d %d",n,m,t[i]);
    }
    for(a=0;a<=m;a++){

        for(b=0;b<n;b++)
        printf("%c",c[b]);

        printf("\n");
        c[a]='^';

       }
    for(a=m;a<T-1;a++){
        c[a-m]='-';
        c[a]='^';
        for(b=0;b<n;b++)
            printf("%c",c[b]);
        printf("\n");
    }
    return 0;

}