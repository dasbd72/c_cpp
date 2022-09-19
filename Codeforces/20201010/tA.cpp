#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, count[3]={}, ans = 0;
    cin >> n;
    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        count[x-1]++;
    }
    sort(count, count+3);
    ans += count[1];
    ans += count[0];
    cout << ans << endl;

}