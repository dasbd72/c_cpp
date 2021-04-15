#include<stdio.h>
int main(){
    double a, b;
    char c;
    scanf("%lf%c%lf",&a,&c,&b);
    if(c == '+'){
        a += b;
    }else if(c == '-'){
        a -= b;
    }else if(c == '*'){
        a *= b;
    }else if(c == '/'){
        if(b != 0) a /= b;
    }
    if(c == '/' && b == 0) printf("Error\n");
    else printf("%.3lf\n", a);
    return 0;
}