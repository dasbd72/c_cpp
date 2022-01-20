#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
#define _ ios::sync_with_stdio(false); cin.tie(0);
pair<int,int> p[300005];
int n, x, inp, arr[300005], max_depth;
long long max_point[300005];
long long dp(int depth);
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> inp, p[i].first = inp;
    for(int i = 0; i < n; i++) cin >> inp, p[i].second = inp;
    sort(p, p+n);
    /*
    cout << "sort : \n";
    for(int i = 0; i < n; i++) cout << i << ' ' <<  p[i].first << ' ' << p[i].second << endl;
    */
    max_depth = p[n-1].first/x;
    cout << dp(0) << endl;
    return 0;
}
long long dp(int depth){
    if(depth > max_depth) return 0;
    /*
    for(int i = 0; i < depth; i++){
        cout << arr[i] << ' ';
    }cout << endl;
    */
    int point = 0, tmp_point;
    if(depth == 0)for(int i = 0; i < n; i++){
        arr[depth] = i;
        tmp_point = dp(depth+1) + p[i].second;
        point = tmp_point > point ? tmp_point : point;
    }
    else if(max_point[arr[depth-1]]){
        point = max_point[arr[depth-1]];
    }
    else for(int i = arr[depth-1]+1; i < n; i++) if(p[i].first - p[arr[depth-1]].first >= x){
        arr[depth] = i;
        tmp_point = dp(depth+1) + p[i].second;
        point = tmp_point > point ? tmp_point : point;
    }
    if(!max_point[arr[depth-1]]) max_point[arr[depth-1]] = point;
    return point;
}