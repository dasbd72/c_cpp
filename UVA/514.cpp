#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool runned = false;
	int N, inp;
	while(cin >> N && N != 0){
		// if(runned) cout << endl;
		// else runned = true;
		while(cin >> inp && inp != 0)
		{
			stack<int> stMid;
			stack<int> stA;
			queue<int> stB;

			for(int i = N; i > 0; i--) stA.push(i);
			for(int i = 0; i < N; i++)
			{
				if(i != 0) cin >> inp;
				stB.push(inp);
			}
			while(!stA.empty())
			{
				while(!stA.empty() && stA.top() != stB.front())
				{
					stMid.push(stA.top());
					stA.pop();
				}
				while(!stA.empty() && stA.top() == stB.front())
				{
					stA.pop();
					stB.pop();
				}
				while(!stMid.empty() && stMid.top() == stB.front())
				{
					stMid.pop();
					stB.pop();
				}
			}
	 		if(stB.empty()) cout << "Yes\n";
	 		else cout << "No\n";
		}
		cout << endl;
	}

}
/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
*/