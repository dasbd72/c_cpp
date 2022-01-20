#include <cstdio>
int n;
double a[10], b[10], c[10];
double S(double t){
    double mx = 0;
    for(int i = 0; i < n; ++i) if(a[i]*(t-b[i])*(t-b[i])+c[i] > mx)
        mx = a[i]*(t-b[i])*(t-b[i])+c[i];
    return mx;
}
int main(){
    int T;
    for(scanf("%d", &T); T; --T){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%lf %lf %lf", &a[i], &b[i], &c[i]);
        double w = 0, x, y, z = 300;
        for(int i = 0; i < 100; ++i){
            x = (z-w)/3.0 + w;
            y = z - (z-w)/3.0;
            if(S(w) < S(x) && S(x) < S(y) && S(y) < S(z)) z = y;
            else if(S(w) > S(x) && S(x) < S(y) && S(y) < S(z)) z = y;
            else if(S(w) > S(x) && S(x) > S(y) && S(y) < S(z)) w = x;
            else if(S(w) > S(x) && S(x) > S(y) && S(y) > S(z)) w = x;
            else w = x, z = y;
        }
        printf("%.5lf\n", S(w));
    }
    return 0;
}
