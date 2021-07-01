#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define MAXN int(2e5+10)

int n, k, u, v, depth[MAXN], son[MAXN], ans;
vector<int> conj[MAXN];
vector<pair<int,int> > best;

bool _compare(pair<int, int> _x, pair<int, int> _y){
    return(_x.first > _y.first);
}
int dfs(int px, int x){
    depth[x] = depth[px] + 1;
    for(vector<int>::iterator iter = conj[x].begin(); iter!=conj[x].end(); iter++)if(*iter != px){
        son[x] += dfs(x, *iter);
    }
    return son[x] + 1;
}
int main(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        conj[u].push_back(v);
        conj[v].push_back(u);
    }
    dfs(0, 1);
    for(int i = 1; i <= n; i++){
        best.push_back(make_pair(depth[i]-son[i], i));
    }
    sort(best.begin(), best.end(), _compare);
    for(int i = 1; i <= k; i++){
        
    }
    cout << ans << endl;
    return 0;
}