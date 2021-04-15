// pass
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, q, arr[2000005], a, b, ra, rb;
long long prefix[2000005], rnum, tnum;
int main(){
    while(scanf("%d %d", &n, &q) != EOF){
        rnum = 0;
        for(int i = 1; i <= n; i++) 
            scanf("%d", arr+i);
        for(int i = 0; i <= n; i++) 
            prefix[i] = (i == 0) ? 0 : arr[i] + prefix[i-1];
        while(q--){
            scanf("%d %d", &a, &b);
            if(a <= b) tnum = prefix[b] - prefix[a-1];
            else tnum = prefix[n] - prefix[a-1] + prefix[b];

            if(tnum > rnum) rnum = tnum, ra = a, rb = b;
        }
        printf("Max_range: (%d,%d); Value: %lld\n", ra, rb, rnum);
    }
}