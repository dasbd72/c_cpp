#include<iostream>
#include<cstring>
using namespace std;

int n, k, t, scoreToGet[100005]={};
string s;

void check(int idx)
{
    if(s[idx] == 'L')
    {
        if(n == 1) scoreToGet[idx] = 1;
        else if(idx == 0) scoreToGet[idx] = s[idx+1] == 'W' ? 2 : 1; //(L)W or (L)L
        else if(idx == n-1) scoreToGet[idx] = s[idx-1] == 'W' ? 2 : 1; //W(L) or L(L)
        else if(s[idx-1] == 'L') scoreToGet[idx] = s[idx+1] == 'W' ? 2 : 1; //L(L)W or L(L)L
        else if(s[idx-1] == 'W') scoreToGet[idx] = s[idx+1] == 'W' ? 3 : 2; //W(L)W or W(L)L
    }
    else if(s[idx] == 'W')
    {
        scoreToGet[idx] = 0;
    }
    return;
}

int getscoreToGetMaxIdx()
{
    int max = 0, idx = -1;
    for(int i = 0; i < n; i++) if(scoreToGet[i] > max)
    {
        idx = i;
        max = scoreToGet[i];
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(cin >> t; t--; )
    {
        cin >> n >> k >> s;
        for(int i = 0; i < n; i++) check(i);
        while(k--)
        {
            int i = getscoreToGetMaxIdx();
            if(i == -1) break;
            else if(s[i] == 'L')
            {
                s[i] = 'W';
                check(i);
                if(i != n-1) check(i+1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(s[i] == 'W')
        {
            if(i == 0) ans+=1;
            else if(i != 0 && s[i-1] == 'W') ans += 2;
            else if(i != 0 && s[i-1] == 'L') ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}