#include<iostream>
#include<vector>
using namespace std;
int n, q, l, r;
vector<int> a;
int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        a.push_back(0);
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        int L, R, M, num;

        L = -1, R = n-1, num = l;
        while(L+1 != R){
            M = (L + R)/2;
            if(a[M] < num) L = M;
            else R = M;
        }
        l = R;

        L = 0, R = n, num = r;
        while(L+1 != R){
            M = (L + R)/2;
            if(a[M] < num) L = M;
            else R = M;
        }
        r = L;

        cout << r - l + 1 << endl;
    }
}
