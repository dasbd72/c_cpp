#include<stdio.h>
#include<stdlib.h>
typedef struct floor
{
    int i;
    struct floor *d[4];
}floor;
int Q, T, dir, val;
const int rdir[]={2,3,0,1};
floor* floor_create(floor* ,int, int);
int main(){
    floor *curr, *portal;
    portal = curr = floor_create(NULL, 0, 0);
    for(scanf("%d", &Q);Q--;){
        scanf("%d", &T);
        if(T == 1) {
            scanf("%d %d", &dir, &val);
            curr->d[dir] = floor_create(curr, rdir[dir], val);
        } else if(T == 2) {
            scanf("%d", &dir);
            curr = curr->d[dir];
        } else if(T == 3) {
            scanf("%d", &val);
            curr -> i = val;
        } else if(T == 4) {
            printf("%d\n", curr->i);
        } else if(T == 5) {
            portal = curr;
        } else {
            curr = portal;
        }
    }
}
floor* floor_create(floor* prev, int dir, int num){
    floor* flr = (floor*)malloc(sizeof(floor));
    flr->i = num;
    flr->d[dir] = prev;
    return flr;
}