#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;
int len(int x);
int main(){
    long long dp[MAX]={0,1};
    for(int i = 2; i < MAX; i++){
        dp[i] = dp[i-1]*i;
        while(dp[i]%10 == 0) dp[i]/=10;
        dp[i] %= 1000000;
    }
    int n;
    while(cin >> n){
        for(int i = 4-len(n); i >= 1; i--) cout << ' ';
        cout << n << " -> " << dp[n]%10 <<endl;
    }
}
int len(int x){
    int l = 0;
    while(x){
        l++;
        x/=10;
    }
    return l;
}