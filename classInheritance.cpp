#include<iostream>
using namespace std;
class base{
private:
    int i;
public:
    base(int i):i(i) {}
    void print() {cout << i << endl;}
};
class inherit : public base{
public:
    inherit(int i):base(i) {}
};
class inherit2 : public inherit{
    inherit2(int i):inherit(i) {}
};
int main(){
}