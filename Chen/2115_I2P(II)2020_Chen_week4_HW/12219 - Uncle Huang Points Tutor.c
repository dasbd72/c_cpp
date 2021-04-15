// pass
#include<stdio.h>
#define ll long long 
ll fp(ll x ,ll y, ll m){
    if(y == 0) return 1%m;
    if(y == 1) return x;
    ll tmp = fp(x, y/2, m);
    tmp = (tmp * tmp) % m;
    if(y % 2 == 0) return tmp;
    else return (tmp*x) % m;
}
int main()
{
    ll x, y, m;
    scanf("%lld %lld %lld", &x, &y, &m);
    printf("%lld\n", fp(x%m, y, m));
}