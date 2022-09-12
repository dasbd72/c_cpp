#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 100; i++) {
        cout << i << "\n";
    }
}
// g++ -std=c++17 -Wall -Wextra -fopenmp -O3 Test.cpp