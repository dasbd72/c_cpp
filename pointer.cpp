#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[][5] = {{10,29,30, 20, 1}, {10,29,80, 20, 1}, {10,29,70, 20, 1}, {10,29,90, 20, 1}, {10,29,10, 20, 1}};
    cout << arr << " " << sizeof(arr) << endl;
    cout << *arr << " " << sizeof(*arr) << endl;
    cout << &arr << " " << sizeof(&arr) << endl;
    for(auto &row : arr){
        cout << row << endl;
        for(auto &col : row){
            cout << col << " " << &col << " ";
        }
        cout << endl;
        for(auto col : row){
            cout << col << " " << &col << " ";
        }
        cout << endl;
    }
}