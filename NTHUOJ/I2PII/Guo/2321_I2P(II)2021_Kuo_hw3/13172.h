#include<iostream>
#include<string>
using namespace std;
class special_power{
public:
    int n;
    special_power(int n);
    int fpow(int x);
    int fpow(int x, int m);
    int fpow();
    string fpow(string s);
    string fpow(string s, int m);
};

#define MOD 880301
special_power::special_power(int n){
    this->n = n;
}
int special_power::fpow(int x){
    return fpow(x, MOD);
}
int special_power::fpow(int x, int m){
    long long num = 1;
    for(int i = 0; i < n; i++){
        num = (x * num) % m;
    }
    return num;
}
int special_power::fpow(){
    return fpow(2);
}
string special_power::fpow(string s){
    string S = "";
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < n; j++) S.push_back(s[i]);
    }
    return S;
}
string special_power::fpow(string s, int m){
    int len = s.length() * n;
    if(len > m) len = m;
    string S = "";
    for(int i = 0; i < s.length() && len; i++){
        for(int j = 0; j < n && len; j++, len--) S.push_back(s[i]);
    }
    return S;
}
