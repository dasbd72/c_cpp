#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int N, M;
int a[12] = {}, b[12] = {};

bool cmp (int a, int b) {
	return a > b;
}

int solve (int *a, int *b) {
	if (a > b || (*(a + 1) != 0) && *(b + 1) == 0) return -1;
	else if (*(a + 1) == 0) return cnt;
	else {
		if (*b - *a < *(a + 1)) return (a + 1, b - a + 1);
		else return (a + 1, b - a);
	}
}

int main () {
	cin >> N >> M;
	for (int i=0;i<N;i++) cin >> a[i];
	for (int i=0;i<M;i++) cin >> b[i];
	sort(a, a+N, cmp);
	sort(b, b+M, cmp);
	
	cnt = (!solve (a, b));
	cout << cnt;
} 
