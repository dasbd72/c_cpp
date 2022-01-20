#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int M = N+N+5;
    M *= N+4;
    M /= 8;
    M -= N-7;
    M %= N;
    cout << "I got " << M << " dollars today!\n";
}