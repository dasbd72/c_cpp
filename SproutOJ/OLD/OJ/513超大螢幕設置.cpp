#include<iostream>
#include<stack>
#include<utility>
using namespace std;
stack<pair<long long, int> > building;
int main(){
    int n;
    long long max = 0, inp, tmp, popped;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inp;
        if(building.empty()) building.push(make_pair(inp, 1));
        else if(inp >  building.top().first) building.push(make_pair(inp, 1));
        else if(inp == building.top().first) building.top().second++;
        else{
            popped = 0;
            while(!building.empty() && inp < building.top().first){
                popped += building.top().second;
                tmp = building.top().first * popped;
                max = tmp > max ? tmp : max;
                building.pop();
            }
            if(building.empty()) building.push(make_pair(inp, popped + 1));
            else if(inp == building.top().first) building.top().second += popped + 1;
            else if(inp >  building.top().first){
                //building.top().second += popped;
                building.push(make_pair(inp, popped + 1));
            }
        }
    }
    popped = 0;
    while(!building.empty()){
        //cout << building.top().first <<endl;
        popped += building.top().second;
        tmp = building.top().first * popped;
        max = tmp > max ? tmp : max;
        building.pop();
        
    }
    cout << max << endl;

}