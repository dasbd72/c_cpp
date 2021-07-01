#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int N, M, A[11], B[11], sol[11];
vector<int> ans;
bool compare(int x, int y){
    return x>y;
}
void solve(int x){
    if(x == N+1){
        int cap[11] = {}, box_num = 0;
        for(int i = 1; i <= M; i++) cap[i] = B[i];
        for(int i = 1; i <= N; i++){
            cap[sol[i]] -= A[i];
            if(cap[sol[i]] < 0) return;
        }
        memset(cap,0,sizeof(cap));
        for(int i = 1; i <= N; i++) cap[sol[i]] = 1;
        for(int i = 1; i <= M; i++) if(cap[i]) box_num++;
        ans.push_back(box_num);
    }
    else for(int i = 1; i <= M; i++){
        sol[x] = i;
        solve(x+1);
    }
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= M; i++) cin >> B[i];
    solve(1);
    sort(ans.begin(), ans.end(), compare);
    if(ans.empty()) cout << -1;
    else cout << ans[0];
    return 0;
}