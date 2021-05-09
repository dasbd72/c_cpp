#include<iostream>
using namespace std;
class base{
private:
    int i;
public:
    base(){
        i = 0;
    }
    int getVal(){
        return i;
    }
    void addVal(){
        i++;
    }
};
class inherit : public base{
private:
    int i;
public:
    inherit(){
        i = 0;
    }
    int getVal2(){
        return i;
    }
    void addVal2(){
        i++;
    }
};
int main(){
    inherit obj;
    obj.addVal();
    cout << obj.getVal() << endl;
    cout << obj.getVal2() << endl;
    obj.addVal2();
    cout << obj.getVal() << endl;
    cout << obj.getVal2() << endl;
}