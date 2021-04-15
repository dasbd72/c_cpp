#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXID 100010
#define SWAP(a,b,t) {t __tmp__ = a; a = b; b = __tmp__;}
typedef struct Data{
    int cnt, status, penalty;
}Data;
typedef struct User{
    int id, cnt, penalty;
    Data* submit;
    struct User *next;
}User;
int skip_space(char*,int);
User *user_create(int id);
int user_cmp(const void*, const void*);
int main(){
    char input[150];
    int inhead = 0, cursor, size = 0;
    User **user, **tosort;
    user = (User**)calloc(MAXID, sizeof(User*));
    tosort = (User**)calloc(MAXID, sizeof(User*));
    while(1){
        // read input
        gets(input);
        // deal with input
        cursor = skip_space(input, 0);
        if(!strncmp(input+cursor, "</table>", 8)) break;
        else if(!strncmp(input+cursor, "<thead>", 7)) inhead = 1;
        else if(!strncmp(input+cursor, "</thead>", 8)) inhead = 0;
        else if(!strncmp(input+cursor, "<tr>", 4)){
            int hr, min, id, status, problem;
            Data *dt_curr;
            // read input in tr
            if(inhead){
                for(int i = 0; i < 4; i++) gets(input);
                continue;
            }
            for(int i = 0; i < 4; i++){
                gets(input);
                cursor = skip_space(input, skip_space(input, 0) + 4);
                if(i == 0){
                    hr = atoi(input+cursor);
                    min = atoi(input+cursor+3);
                }
                else if(i == 1) id = atoi(input+cursor);
                else if(i == 2) problem = input[cursor]-'A';
                else if(i == 3){
                    if(input[cursor] == 'A') status = 1;
                    else status = 0;
                }
            }
            // printf("%02d:%02d %d %d %d\n", hr, min, id, problem, status);
            if(user[id] == NULL) user[id] = user_create(id);
            dt_curr = &(user[id]->submit[problem]);
            if(dt_curr->status == 0){
                if(status){
                    dt_curr->status = 1;
                    dt_curr->penalty = 20 * dt_curr->cnt + hr*60 + min;
                    user[id]->cnt++;
                    user[id]->penalty += dt_curr->penalty;
                }
                dt_curr->cnt++;
            }
        }
    }
    for(int i = 0; i < MAXID; i++) {
        if(user[i] != NULL) tosort[size++] = user[i];
    }
    qsort(tosort, size, sizeof(User*), user_cmp);
    for(int i = 0; tosort[i] != NULL; i++){
        printf("%d ", tosort[i]->id);
        for(int j = 0; j < 10; j++){
            Data* dt_curr = &(tosort[i]->submit[j]);
            char x[100], y[100];
            sprintf(x,"%d",dt_curr->cnt);
            sprintf(y,"%d",dt_curr->penalty);
            printf("%s/%s ", dt_curr->cnt?x:"-", dt_curr->status?y:"-");
        }
        printf("%d %d\n", tosort[i]->cnt, tosort[i]->penalty);
    }
}

int skip_space(char* str,int idx){
    while(str[idx] == ' ') idx++;
    if(str[idx] == '\0') return -1;
    else return idx;
}
User *user_create(int id){
    User *tmp = (User*)calloc(1, sizeof(User));
    tmp->id = id;
    tmp->submit = (Data*)calloc(10, sizeof(Data));
    return tmp;
}
int user_cmp(const void* a, const void* b){
    User *x = *(User**)a, *y = *(User**)b; 
    if(x->cnt < y->cnt) return 1;
    if(x->cnt > y->cnt) return -1;
    if(x->penalty > y->penalty) return 1;
    if(x->penalty < y->penalty) return -1;
    if(x->id > y->id) return 1;
    if(x->id < y->id) return -1;
    return 0;
}