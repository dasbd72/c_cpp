#include <iostream>
#include <vector>
using namespace std;
vector<int> ans[10001];
void times(int x);
int len(int x);
int main(){
    ans[1].push_back(1);
    for(int i = 2; i < 10001; i++){
        ans[i].assign(ans[i-1].begin(), ans[i-1].end());
        times(i);
    }
    int n;
    while(cin >> n){
        cout << n <<'!'<<endl;
        for(int i = ans[n].size()-1; i >= 0; i--){
            cout << ans[n][i];
        }cout << endl;
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
void times(int x){
    int tmp = 0, s = ans[x].size();
    for(int i = s-1; i >= 0; i--){
        ans[x][i] *= x;
        tmp = ans[x][i]/10;
        ans[x][i] %= 10;
        int j = i+1;
        while(tmp){
            if(j >= ans[x].size()) ans[x].push_back(0);
            ans[x][j] += tmp%10;
            tmp/=10;
            if(ans[x][j] > 9){
                tmp += ans[x][j]/10;
                ans[x][j]%=10;
            }
            j++;
            
        }
    }
}