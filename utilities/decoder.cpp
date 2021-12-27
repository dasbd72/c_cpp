#include <iostream>
using namespace std;
void print_binary(int number, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        cout << ((1 << i) & number ? 1 : 0);
    }
}
int main() {
    for (int i = 0; i <= 100; i++) {
        cout << "8'b";
        print_binary(i, 8);
        cout << ": number_decoded[11:0] = 12'b";
        if (i == 100)
            cout << "0001";
        else
            cout << "1111";
        cout << "_";
        if (i >= 10)
            print_binary((i / 10) % 10, 4);
        else
            cout << "1111";
        cout << "_";
        print_binary(i % 10, 4);
        cout << ";\n";
    }
}