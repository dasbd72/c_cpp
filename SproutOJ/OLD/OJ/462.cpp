#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string inp_s, tmp_s, command;
    int N, len;
    long long a;
    cin >> inp_s >> N;
    len = inp_s.length();
    while(N--){
        cin >> command >> a;
        if(command[0] == 'u'){
            a %= 26;
            for(int i = 0; i < len; i++){
                if(inp_s[i]+a > 'z') inp_s[i] += a - 26;
                else inp_s[i] += a;
            }
        }
        if(command[0] == 'd'){
            a %= 26;
            for(int i = 0; i < len; i++){
                if(inp_s[i]-a < 'a') inp_s[i] += 26 - a;
                else inp_s[i] -= a;
            }
        }
        if(command[0] == 'l'){
            a %= len;
            tmp_s.clear();
            tmp_s.append(inp_s.substr(a, len - a));
            tmp_s.append(inp_s.substr(0, a));
            inp_s.clear();
            inp_s.append(tmp_s);
        }
        if(command[0] == 'r'){
            a %= len;
            tmp_s.clear();
            tmp_s.append(inp_s.substr(len - a, a));
            tmp_s.append(inp_s.substr(0, len - a));
            inp_s.clear();
            inp_s.append(tmp_s);
        }
        command.clear();
        cout << inp_s << endl;
    }
}