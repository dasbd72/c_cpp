#include<iostream>
#include<cstring>
#include <cstdlib>
using namespace std;
int len(int x){
    int count = 0;
    while(x){
        x /= 10;
    }
    return count;
}
/*
int main(){
    long long int a, b, m;
    cin >> a >> b >> m;
    a %= m;
    b %= m;
    a %= 2;
    b %= 2;
    cout << a*b << endl;
    return 0;
}
int main(){
    string a, b;
    long long int x, y, m;
    cin >> a >> b >> m;
    int l = len(m)+1;
    if(a.size() < l) x = atoi(a.c_str());
    else x = atoi(a.substr(a.size()-l, l).c_str());
    if(b.size() < l) y = atoi(b.c_str());
    else y = atoi(b.substr(b.size()-l, l).c_str());

    cout << (x * y)%m%2 << endl;
    return 0;
}
int main(){
    string a, b;
    long long int x, y, m;
    cin >> a >> b >> m;
    x = a[a.size()-1] - '0';
    y = b[b.size()-1] - '0';
    if(m%2 == 0){
        if(x%2 == 0 || y%2 == 0) cout << 0;
        else cout << 1;
    }
    else{

    }
    cout << endl;
    return 0;
}
*/
int main(){
    string a, b;
    long long int m;
    cin >> a >> b >> m;
    m/=10;
    cout << m % 2 << endl;
    return 0;
}