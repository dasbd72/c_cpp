#include <iostream>
using namespace std;
int sum(int n) {
    if (n == 2)
        return n;
    else if (n <= 1)
        return 0;
    else {
        if ((n % 2) == 0)
            return sum(n - 2) + n;
        else
            return sum(n - 1);
    }
}
int main() {
    cout << sum(10) << endl;
}