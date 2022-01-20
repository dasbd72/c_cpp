#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b,c) {c=a;a=b;b=c;}
typedef struct
{
    long long tot;
    int max, pn, idx;
    int *mk;
}GROUP;
int T, N;
GROUP *ptr[2000], *tmpG;
int compare(GROUP*, GROUP*);
int main(){
    for(scanf("%d", &T); T--; ){
        //input
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            ptr[i] = (GROUP*)calloc(1,sizeof(GROUP));
            scanf("%d", &ptr[i]->pn);
            ptr[i]->idx = i;
            ptr[i]->mk = (int*)malloc(ptr[i]->pn * sizeof(int));
            for(int j = 0; j < ptr[i]->pn; j++){
                scanf("%d", &ptr[i]->mk[j]);
                ptr[i]->tot += ptr[i]->mk[j];
                ptr[i]->max = ptr[i]->mk[j] > ptr[i]->max ? ptr[i]->mk[j] : ptr[i]->max;
            }
        }
        // Bubble Sort of the groups
        for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++){
            if(compare(ptr[i], ptr[j])) SWAP(ptr[i], ptr[j], tmpG);
        }
        // Output
        for(int i = 0; i < N; i++) for(int j = 0; j < ptr[i]->pn; j++)
            j == ptr[i]->pn-1 ? printf("%d\n", ptr[i]->mk[j]) : printf("%d ", ptr[i]->mk[j]);
        // Release memory
        for(int i = 0; i < N; i++){
            free(ptr[i]->mk);
            free(ptr[i]);
        }
    }
}

int compare(GROUP *x, GROUP *y){ // 0 if dont need to exchange and 1 if need
    if(x->tot > y->tot) return 0;
    if(x->tot < y->tot) return 1;
    if(x->max > y->max) return 0;
    if(x->max < y->max) return 1;
    if(x->pn > y->pn) return 0;
    if(x->pn < y->pn) return 1;
    if(x->idx < y->idx) return 0;
    if(x->idx > y->idx) return 1;
    return 0;
}
