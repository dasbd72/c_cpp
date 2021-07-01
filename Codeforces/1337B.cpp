#include <iostream>
#include <cmath>
using namespace std;
int t, x, n, m;
int va(int point){
    return (floor(point/2) + 10);
}
int ls(int point){
    return point-10;
}
int main(){
    for(cin >> t; t; t--){
        cin >> x >> n >> m;
        while(x > 20 && n--){
            x = va(x);
        }
        while(x > 0 && m--){
            x = ls(x);
        }
        if(x > 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}