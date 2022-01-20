#include<iostream>
#include<cstring>
using namespace std;
string S;
int flag[6010];
void tag(string str, int index){
    int start = 0;
    while(start < S.size()){
        start = S.find(str, start);
        if(start >= S.size()) break;
        else{
            flag[start] = index;
            start += 3;
        }
    }
}
int main(){
    cin >> S;
    tag("ATG",1);
    tag("TAG",2);
    tag("TAA",2);
    tag("TGA",2);
    int _start = S.size(), _exist = 0, _dnalen;
    //for(int i = 0; i < S.size(); i++) cout << flag[i]; cout << endl;
    for(int i = 0; i < S.size(); i++){
        if(flag[i] == 1)_start = i + 3;
        else if(flag[i] == 2){
            //cout << "start: " << _start << " end: " <<i << endl;
            _dnalen = i - _start;
            if(_dnalen > 0 && _dnalen % 3 == 0) {
                cout << S.substr(_start,_dnalen) << endl;
                _exist = 1;
            }
            _start = S.size();
        }
    }
    if(!_exist) cout << "No gene.\n";
}
