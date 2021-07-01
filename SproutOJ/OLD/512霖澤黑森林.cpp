#include<iostream>
#include<stack>
#define MAX 200005
using namespace std;
int main(){
    int n, a[MAX]={}, fail = 0;
    stack<int> bottle;
    cin >> n;
    while(n--){
        int y;
        cin >> y;
        if(!fail && y < 0 && bottle.empty()) fail = 1;
        else if(!fail && y < 0 && -y == bottle.top()) bottle.pop();
        else if(!fail && y > 0) bottle.push(y);
    }
    if(fail || !bottle.empty()) cout << "lose light light\n";
    else cout << "weed\n";
}