#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	string s;
	while(cin>>s)
	for(int i = 0; i < s.size(); i++){
		for(int k = 0, flag = 1; k <= i+1 && flag; k++){
			string m; m.append(&s[0],&s[i-k+1]);
			vector<int> len;
			
			for(int t = 0; t < i-k+1 && flag; t++)for(int r = 0; r < m.size() && flag; r++){
				if(s[t+r]!=m[r]) break;
				else if(len.empty()||(r == m.size()-1 && len.back()+m.size()-1+k >= t-1)) len.push_back(t);
				else break;
				if(t==i-k && r==m.size()-1){
					flag == 0;
					cout<< k << '\n';
					break;
				}
			}
			
			//cout << m << '\n';
		}
	}
}

