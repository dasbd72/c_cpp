#include<iostream>
#include<queue>
using namespace std;
struct tree{
    int x;
    tree *rchild = NULL, *lchild = NULL, *mother = NULL;
};
int main(){
    int N, x; cin >> N;
    tree *root = new tree, *now;
    char command[10];
    cin >> command >> x;
    root->x = x;
    N--;
    while(N--){
        cin >> command >> x;
        now = root;
        if(command[0]=='i'){
        }
        else if(command[0]=='d'){
        }
        else if(command[0]=='q'){
        }
    }
}