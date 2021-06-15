// #include <iostream>
// #include <string>
// using namespace std;
// class Human {
//    public:
//     Human(string name, int age) : Name(name), Age(age) {
//         cout << "Human " << name << " created" << endl;
//     }
//     virtual void SelfIntroduce() {
//         cout << "Hello! My name is " << this->Name;
//         cout << ", " << this->Age << " years old." << endl;
//     }

//    protected:
//     string Name;
//     int Age;
// };
// class Engineer : public Human {
//    public:
//     Engineer(string name, int age) : Human(name, age) {}
//     void SelfIntroduce() override {
//         cout << "HAHAHAHAHA" << endl;
//     }
//     virtual void WriteCode() {
//         cout << "Coding..." << endl;
//     }
// };
// class Poorgramer : public Engineer {
//    public:
//     Poorgramer(string name, int age) : Engineer(name, age) {}
//     virtual void SelfIntroduce() {
//         cout << "Hello! My name is " << this->Name;
//         cout << ", " << this->Age << " years old." << endl;
//         cout << "As a poorgramer, I have to write code day and night." << endl;
//     }
// };
// int main() {
//     Poorgramer Mike("Mike", 18);
//     Engineer *human = &Mike;
//     Mike.SelfIntroduce();
//     Mike.WriteCode();
//     cout << "-----------" << endl;
//     human->SelfIntroduce();
//     return 0;
// }

// #include <iostream>
// class Foo {
//    public:
//     void print() {
//         std::cout << "Foo\n";
//     }
// };
// class Bar : public Foo {
//    public:
//     void print() {
//         std::cout << "Bar\n";
//     }
// };
// int main() {
//     Foo a;
//     a.print();
//     Bar b;
//     b.print();
//     Foo* c = new Bar();
//     c->print();
//     return 0;
// }

#include <cmath>
#include <iostream>
// template <typename T, class Func>
void ForEach(int* _begin, int* _end, void (*_func)(int&)) {
    for (; _begin != _end; _begin++) {
        _func(*_begin);
    }
}
struct Power {
    int exp = 2;
    void operator()(int& base) {
        base = std::pow(base, exp);
    }
};
void func(int& base) {
    base = std::pow(base, 2);
}
int main() {
    int A[] = {1, 2, 3, 4, 5};
    ForEach(A, A + 5, func);
    return 0;
}