#include <bits/stdc++.h>
using namespace std;
int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char map[12][12];

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            std::cin >> map[i][j];
        }
    }

    // for(int i = 1; i <= 10; i++){
    //     for(int j = 1; j <= 10; j++){
    //         std::cout << map[i][j];
    //     }
    //     std::cout << "\n";
    // }

    for(int d = 0; d < 8; d++){
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++){
                if(map[i][j] == 'X'){
                    int cnt = 1;
                    bool availible = false;
                    for(int t = 1; t < 5 && j + t * dj[d] <= 10 && j + t * dj[d] >= 1 && i + t * di[d] <= 10 && i + t * di[d] >= 1; t++){
                        if(map[i + t * di[d]][j + t * dj[d]] == 'X')
                            cnt++;
                        else if(map[i + t * di[d]][j + t * dj[d]] == 'O')
                            cnt = -5;
                        if(t == 4) availible = true;
                    }
                    if(availible && cnt == 4){
                        std::cout << "YES\n";
                        // std::cout << i << ", " << j << ", " << d << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    std::cout << "NO\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 B.cpp ; ./a.out <B.in