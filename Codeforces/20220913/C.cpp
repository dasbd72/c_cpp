#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    long long a[1005];
    
    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    
    int y = 0;

    // for(int i = 0; i < n; i++) {
    //     std::cout << a[i] << " ";
    // }

    for(int i = 0; i < n; i++) {
        while(k < (double)a[i] / 2) {
            k *= 2;
            y++;
        }
        if(a[i] > k) k = a[i];
    }

    std::cout << y << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 C.cpp ; ./a.out <C.in
// g++ -std=c++17 -Wall -Wextra -g -O2 C.cpp ; ./a.exe