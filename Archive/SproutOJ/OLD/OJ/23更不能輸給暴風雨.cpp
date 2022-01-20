#include<iostream>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
/*
void no_solution();
void solve(int N,int order[]);
queue<int> _0, _3;
stack<int> _1, _2;
*/
stack<int> gt01, gt02;
queue<int> ord;
void solve(int N,int order[]){
    for(int i = 0; i < N; i++)
        ord.push(order[i]);
    for(int i = 1; i <= N; i++){
        gt01.push(i);
        push_train();
        while(!gt01.empty() && !ord.empty() && gt01.top() == ord.front()){
            move_station_1_to_2();
            pop_train();
            ord.pop();
            gt01.pop();
        }
    }
    while(!gt01.empty() || !gt02.empty()){
        while(!gt01.empty()){
            if(gt01.top() == ord.front()){
                move_station_1_to_2();
                pop_train();
                ord.pop();
                gt01.pop();
            }
            else{
                gt02.push(gt01.top());
                move_station_1_to_2();
                gt01.pop();
            }
        } 
        while(!gt02.empty()){
            if(gt02.top() == ord.front()){
                pop_train();
                ord.pop();
                gt02.pop();
            }
            else {
                gt01.push(gt02.top());
                move_station_2_to_1();
                gt02.pop();
            }
        }
    }
}
/*
int main(){
    int n, x;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        _0.push(i+1);
    }
    solve(n, arr);
    for(int i = 0; i < n; i++){
        if(!arr[i] == _3.front()){
            cout << "wrong\n";
            break;
        }
        else if(i == n-1)cout << "correct\n";
    }
}
void push_train(){
    _1.push(_0.front());
    _0.pop();
}
void move_station_1_to_2(){
    _2.push(_1.top());
    _1.pop();
}
void move_station_2_to_1(){
    _1.push(_2.top());
    _2.pop();
}
void pop_train(){
    _3.push(_2.top());
    _2.pop();
}
void no_solution(){
    cout << "no ans\n";
}
*/