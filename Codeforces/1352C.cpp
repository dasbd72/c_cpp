#include<iostream>
using namespace std;
int t, n, k;
int main(){
    for(cin >> t; t; t--){
        cin >> n >> k;
        if(n-1 >= k) cout << k << endl;
        else{
            k = k-(n-1);
            
        }
    }
}