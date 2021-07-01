#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    int T;cin >> T;
    while(T--){
        int N; cin >> N;
        stack<int> tmp;
        queue<int> order;
        for(int i = 1, x; i <= N; i++){
            cin >> x;
            order.push(x);
        }
        for(int i = 1; i <= N; i++){
            if(i == order.front()){
                order.pop();
            }
            else tmp.push(i);
            while(!tmp.empty() && !order.empty() && tmp.top() == order.front()){
                tmp.pop();
                order.pop();
            }
        }
        if(tmp.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}