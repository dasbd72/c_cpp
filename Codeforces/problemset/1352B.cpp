#include<iostream>
using namespace std;
int t, n, k, ans = 0;
bool odd(int num);
bool even(int num);
int main(){
    for(cin >> t; t; t--){
        cin >> n >> k;
        if(odd(n)){
            cout << "YES\n";
            for(int i = 0; i < k-1; i++) cout << "1 ";
            cout << n-k+1 << endl;
        }
        else if(even(n)){
            cout << "YES\n";
            for(int i = 0; i < k-1; i++) cout << "2 ";
            cout << n-2*(k-1) << endl;
        }
        else cout << "NO\n";
    }
    return 0;
}
bool odd(int num){
    num-=k-1;
    if(num > 0 && num%2 == 1)return true;
    else return false;
}
bool even(int num){
    num-=2*(k-1);
    if(num > 0 && num%2 == 0)return true;
    else return false;
}