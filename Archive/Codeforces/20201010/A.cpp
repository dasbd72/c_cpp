#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    for(cin >> t; t--; )
    {
        vector<int> a;
        int n, count = 0;
        cin >> n;
        for(int i = 0, inp; i < n; i++)
        {
            cin >> inp;
            a.push_back(inp);
            count += inp;
        }
        if(count == 0) cout << "NO\n";
        else
        {
            if(count < 0) sort(a.begin(), a.end());
            else sort(a.begin(), a.end(), greater<int>() );
            cout << "YES" << endl;
            for(int i = 0; i < a.size(); i++) i == a.size()-1 ? cout << a[i] << endl : cout << a[i] << ' ';
        }
    }
    return 0;
}