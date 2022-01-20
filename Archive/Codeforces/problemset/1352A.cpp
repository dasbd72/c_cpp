#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, num, count, power;
    vector<int> ans;
    for(cin >> n; n; n--){
        cin >> num;
        count = 0;
        power = 1;
        ans.clear();
        int i = 0;
        while(num){
            if(num % 10){
                ans.push_back((num % 10) * power);
                count++;
            }
            num /= 10;
            i++;
            power*=10;
        }
        cout << count << endl;
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
            cout << *it;
            if(it+1 != ans.end()) cout << ' ';
        }cout << endl;
    }
    return 0;
}