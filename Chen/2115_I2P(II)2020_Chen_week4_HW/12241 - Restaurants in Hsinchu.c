// pass
#include<stdio.h>
#define ll long long
#define MOD 1000000007
#define mod(a) (a%MOD)
typedef struct Array
{
    ll a, b, c, d;
}Array;
Array create(ll a, ll b, ll c, ll d){
    return (Array){
        a, b, c, d
    };
}
Array multi(Array A, Array B){
    return create(mod(mod(A.a*B.a)+mod(A.b*B.c)), mod(mod(A.a*B.b)+mod(A.b*B.d)), 
    mod(mod(A.c*B.a)+mod(A.d*B.c)), mod(mod(A.c*B.b)+mod(A.d*B.d)));
}
Array fastpow(Array A, ll pow){
    if(pow == 0) return create(1,0,0,1);
    if(pow == 1) return A;
    Array tmp = fastpow(A, pow / 2);
    tmp = multi(tmp, tmp);
    if(pow % 2) tmp = multi(tmp, A);
    return tmp;
}
int main(){
    for(ll x; scanf("%lld", &x) != EOF;){
        if(x >= 3){
            Array A;
            A = fastpow(create(1,1,1,0), x-2);
            printf("%lld\n", (A.a + A.b) % MOD);
        }
        else printf("1\n");
    }
}