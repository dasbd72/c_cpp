#include<iostream>
using namespace std;
class myClass{
public:
    int a = 1, b = 1, c = 1;
    myClass():a{2}, b{2}, c{2}{
    }
};
int main(){
    myClass obj = {10, 10, 10};
    cout << obj.a << " " << obj.b << " " << obj.c;
}