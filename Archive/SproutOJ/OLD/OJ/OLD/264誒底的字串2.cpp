#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	string A;
	int min, tmp, cont;
	cin >> A;
	
	for(int i = A.size()-1; i >= A.size()/2; i--)
	if(A[i] == A[0] && A.size() % (A.size()-i) == 0){
		cont = 1;
		for(int a = 0; a < A.size() && cont; a+=(A.size()-i))
		for(int m = a, n = i; n < A.size(); m++, n++){
			if(A[m] != A[n]){
				cont = 0;
				break;
			}
			else if(A[m] == A[n] && m == A.size()-1){
				cout << A.size() - i << '\n';
				return 0;
			}
		}
	}
	cout << A.size() << '\n';
	return 0;
}

