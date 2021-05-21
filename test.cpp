#include <iostream>

using namespace std;

class A {
public:
    A() {};
    ~A() {};
    void f() {
        cout << "Calling A\n";
    };
};

class B : virtual public A {
public:
    B() : A() {};
    ~B() {};
    void f() {
        cout << "Calling B\n";
    };
};

class C : virtual public A {
public:
    C() : A() {};
    ~C() {};
    void f() {
        cout << "Calling C\n";
    };
};

class D : public B, public C {
public:
    D() : A(), B(), C() {};
    ~D() {};
    void f(){
        cout << "Calling D\n";
    };
};

int main() {
    string s("1234");
    cout << s.substr(3, -3);
}