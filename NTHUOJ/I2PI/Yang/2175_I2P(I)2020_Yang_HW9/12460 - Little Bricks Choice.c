#include<stdio.h>
#include<string.h>
char s[20], len;
int picked, set;
void sort(int, int);
void pick(int, int);
void output();
int main()
{
    scanf("%s", s);
    len = strlen(s), picked  = 0, set = 0;
    sort(0, len);
    pick(0, 0);
    printf("\n");
}
void output(){
    if(picked) printf(", ");
    else picked = 1;
    for(int i = 0; i < len; i++) if(set & (1 << i) ) printf("%c", s[i]);
}
void pick(int pos, int cnt){
    if(cnt == 4) output();
    if(pos == len) return;
    else{
        set |= (1 << pos);
        if(cnt >= 4) output();
        pick(pos+1, cnt+1);
        set -= (1 << pos);
        pick(pos+1, cnt);
        return;
    }
}
void sort(int l, int r) // sort from l to r-1
{
    if(l+1 == r) return;
    int mid = (l + r) / 2, li = 0, ri = 0, i = l;
    char ls[20], rs[20];
    sort(l, mid);
    sort(mid, r);
    strncpy(ls, s+l, mid-l);
    strncpy(rs, s+mid, r-mid);
    while(li < mid-l && ri < r-mid){
        if(ls[li] <= rs[ri]) s[i++] = ls[li++];
        else s[i++] = rs[ri++];
    }
    while(li < mid-l) s[i++] = ls[li++];
    while(ri < r-mid) s[i++] = rs[ri++];
    return;
}