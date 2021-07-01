#include<iostream>
using namespace std;
int main(){
    int x, y;
    cin.get();
    cin >> x;
    cin.get();
    cin >> y;
    y = 2 * (x + y);
    x = 2 * (x + 3);
    cout << "(" << x << "," << y << ")" << endl;
}