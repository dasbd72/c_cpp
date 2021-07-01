#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct line{
    bool in_line = false;
    queue<int> q;
};
int team[1000005];
int main(){
int N, count = 1;
while(cin >> N){
    cout << "Line #" << count++ << endl;
    //初始化
    memset(team, 0, sizeof(team));
    int x, K;
    queue<line*> tot_line;
    string command;
    line *ptr[N];
    
    for(int i = 1; i <= N; i++){
        //設定編號
        cin >> K;
        while(K--){
            cin >> x;
            team[x] = i;
        }
        ptr[i] = new line(); 
    }

    while(cin >> command){
        //讀指令
        if(command[0] == 'S') break;
        else if(command[0] == 'E'){
            cin >> x;
            if(team[x] == 0){
                line *single = new line();
                single->in_line = true;
                single->q.push(x);
                tot_line.push(single);
            }
            else{
                if(!ptr[team[x]]->in_line){
                    tot_line.push(ptr[team[x]]);
                    ptr[team[x]]->in_line = true;
                }
                ptr[team[x]]->q.push(x);
            }
        }
        else{
            cout << tot_line.front()->q.front() << endl;
            tot_line.front()->q.pop();
            if(tot_line.front()->q.empty()){
                tot_line.front()->in_line = false;
                tot_line.pop();
            }
        }
    }
}
}