#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
typedef struct Node{
    char c;
    struct Node *next;
}Node;
void init_line(Node **head);
void delete_line(Node **head);
void print_line(int i, Node *head);
Node *createNode(char ch, Node* r);
Node *insertNode(char ch, Node* l);
Node *deleteNode(Node* curr);
Node *findcolNode(Node* head, int col);
int main(){
    int T, leninp;
    char inp[2005];
    int curmode = 0; // 0:command 1:user
    int injk;
    int col, colmem, row, prefix, rep;
    Node *line[1001], *cursor;
    scanf("%d", &T);
    for(int t = 1;t <= T; t++){
        scanf("%s", inp);
        leninp = strlen(inp);
        for(int i = 1; i <= 1000; i++) init_line(&line[i]);
        cursor = line[1];
        col = colmem = 0, row = 1, rep = 1;
        curmode = 0;
        for(int i = 0; i < leninp; i++){
            // printf("%d,%d %c\n", row, col, inp[i]);
            prefix = 1;
            injk = 0;
            if(curmode == 0){
                if(strncmp(inp+i, ":wq", 3) == 0) break;

                if(isdigit(inp[i])){
                    prefix = atoi(inp+i);
                    while(isdigit(inp[i])) i++;
                    //printf("%d isdigit\n", i);
                }

                if(inp[i] == 'a'){
                    curmode = 1;
                    rep = prefix;
                }else if(inp[i] == 'i'){
                    curmode = 1;
                    rep = prefix;
                    if(cursor->c != 0){
                        col--;
                        cursor = findcolNode(line[row], col);
                    }
                }else if(inp[i] == 'A'){
                    curmode = 1;
                    rep = prefix;
                    cursor = line[row];
                    col = 0;
                    while (cursor->next->c != 0){
                        cursor = cursor->next;
                        col++;   
                    }
                }else if(inp[i] == 'I'){
                    curmode = 1;
                    rep = prefix;
                    cursor = line[row];
                    col = 0;
                }else if(inp[i] == 'h'){
                    if(col != 0){
                        col = col - prefix;
                        if(col < 1) col = 1;
                        cursor = findcolNode(line[row], col);
                    }
                }else if(inp[i] == 'l'){
                    while(cursor->c != 0 && cursor->next->c != 0 && prefix--){
                        cursor = cursor->next;
                        col++;
                    }
                }else if(inp[i] == 'x'){
                    while(cursor->c != 0 && prefix--){
                        cursor = deleteNode(cursor);
                        if(cursor->c == 0){
                            col--;
                            cursor = findcolNode(line[row], col);
                            break;
                        }
                    }
                }else if(inp[i] == 'j'){
                    injk = 1;
                    prefix = row + prefix;
                    if(prefix > 1000) prefix = 1000;
                    while(row+1 <= prefix){
                        row++;
                        cursor = line[row];
                        int j = 0;
                        while(j+1 <= colmem && cursor->next->c != 0){
                            cursor = cursor->next;
                            j++;
                        }
                        col = j;
                    }
                }else if(inp[i] == 'k'){
                    injk = 1;
                    prefix = row - prefix;
                    if(prefix < 1) prefix = 1;
                    while(row-1 >= prefix){
                        row--;
                        cursor = line[row];
                        int j = 0;
                        while(j+1 <= colmem && cursor->next->c != 0){
                            cursor = cursor->next;
                            j++;
                        }
                        col = j;
                    }
                }

                if(!injk)colmem = col;
            } 
            else if(curmode == 1) {
                int end = i;
                char str[1000];
                curmode = 0;
                while(strncmp(inp+end, "ESC", 3) != 0) end++;
                strncpy(str, inp+i, end-i);
                while(rep--){
                    for(int j = 0; j < end - i; j++){
                        cursor = insertNode(str[j], cursor);
                        col++;
                    }
                }

                if(cursor->c == 0 && cursor->next->c != 0){
                    cursor = cursor->next;
                    col++;
                }
                colmem = col;
                i =  end + 2;
            }
            // for(int _i = 1; _i <= 1000; _i++) print_line(_i, line[_i]);
        }
        printf("Case #%d:\n", t);
        for(int _i = 1; _i <= 1000; _i++) print_line(_i, line[_i]);
        for(int i = 1; i <= 1000; i++) delete_line(&line[i]);
    }
    
}
void init_line(Node **head){
    (*head) = createNode(0, NULL);
    (*head)->next = createNode(0, NULL);
}
void delete_line(Node **head){
    Node *tofree;
    tofree = NULL;
    while((*head) != NULL){
        tofree = (*head);
        (*head) = (*head)->next;
        free(tofree);
    }
    (*head) = NULL;
}
void print_line(int i, Node *head){
    Node *curr = head->next;
    if(curr->c != 0){
        printf("%d: ", i);
        while(curr->c != 0){
            printf("%c", curr->c);
            curr = curr->next;
        }
        printf("\n");
    }
    
    return;
}
Node *createNode(char ch, Node* r){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = ch;
    tmp->next = r;
    return tmp;
}
Node *insertNode(char ch, Node* curr){
    Node *tmp = createNode(ch, curr->next);
    curr->next = tmp;
    return tmp;
}
Node *deleteNode(Node* curr){
    Node *tofree = curr->next;
    curr->c = curr->next->c;
    curr->next = curr->next->next;
    free(tofree);
    return curr;
}
Node *findcolNode(Node* head, int col){
    while (col-- && head->next->c != 0)
        head = head->next;
    return head;
}
/*
1
aabcESCjaabcESC:wq

1
aabcESChaiESC:wq

1
aabcESC2x:wq

10
iaESCjibcESC
iaESCjibcESCjidefESC
iaESCjibcESCjidefESC2jighiESC
iaESCjibcESCjidefESC2jighiESC2jAlESC
iaESCjibcESCjidefESC2jighiESC2jAlESCkajkESC
iaESCjibcESCjidefESC2jighiESC2jAlESCkajkESC1234kIxESC
iaESCjibcESCjidefESC2jighiESC2jAlESCkajkESC1234kIxESCjIyESC:wq

5
AabcESC
AabcESCjIdefESC
AabcESCjIdefESCjighiESC
AabcESCjIdefESCjighiESCjajklESC
AabcESCjIdefESCjighiESCjajklESCkxkxkljjjx:wq
*/