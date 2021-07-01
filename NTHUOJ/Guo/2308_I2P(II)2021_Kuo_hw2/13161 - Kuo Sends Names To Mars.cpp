#include<iostream>
#include<string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < S.length(); i++){
        int i2 = i + 1, i3 = i + 2;
        if(i2 < S.length() && S[i] == S[i2] && S[i] != 'X' && S[i2] != 'X') ans++, S[i2] = 'X';
        if(i3 < S.length() && S[i] == S[i3] && S[i] != 'X' && S[i3] != 'X') ans++, S[i3] = 'X';
    }
    cout << ans << endl;
}