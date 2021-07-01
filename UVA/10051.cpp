#include<iostream>
#include<utility>
using namespace std;
#define MAX 501
int main(){
    int N; 
    int cube[MAX][6]={};
    while(cin >> N){
        if(N == 0)break;
        for(int i = 0; i < N; i++)for(int j = 0; j < 6; j++){
            cin >> cube[i][j];
        }
        
    }
}