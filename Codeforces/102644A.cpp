#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define _ cin.tie(0); ios::sync_with_stdio(false);
#define pdb pair<double, bool>
int main() {_
    double n, p, ans = 0;
    queue <pdb > que;
    que.push(pdb(1,1));
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int qsize = que.size();
        for(int j = 0; j < qsize; j++){
            double _p = que.front().first;
            bool _ishappy = que.front().second;
            que.pop();
            if(i != n){
                que.push(pdb(_p*p,!_ishappy));
                que.push(pdb(_p*(1-p),_ishappy));
            }
            else{
                if(_ishappy) ans += _p*(1-p);
                else ans += _p*p;
            }
        }
    }
    cout << ans << endl;
}