#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, cmd, x , cntEle;
    bool isqu, isst, ispq;
    while(cin >> n)
    {
    	isqu = true, isst = true, ispq = true;
    	cntEle = 0;
    	queue<int> qu;
    	stack<int> st;
    	priority_queue<int> pq;
    	while(n--)
    	{
    		cin >> cmd >> x;
    		if(cmd == 1)
    		{
    			qu.push(x);
    			st.push(x);
    			pq.push(x);
    			cntEle ++;
    		}
    		else if(cntEle-- > 0)
    		{
    			if(isqu)
    			{
    				if(qu.front() != x) isqu = false;
    				else qu.pop();
    			}
    			if(isst)
    			{
    				if(st.top() != x) isst = false;
    				else st.pop();
    			}
    			if(ispq)
    			{
    				if(pq.top() != x) ispq = false;
    				else pq.pop();
    			}
    		}
    		else isqu = ispq = isst = false;
    	}
    	if(!ispq && !isst && !isqu) cout << "impossible" << endl;
    	else if((ispq || isqu)&&(isqu || isst)&&(isst || ispq)) cout << "not sure" << endl;
    	else if(ispq) cout << "priority queue" << endl;
    	else if(isst) cout << "stack" << endl;
    	else if(isqu) cout << "queue" << endl;
    }
    return 0;
}
/*
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4
*/