#include <stdio.h>
#include <string.h>
typedef struct Node {
    char* str;
    Node* nxt;
} Node;
Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nxt = NULL;
    if (str)
        newNode->str = str;
    return newNode;
}
int main() {
    int N, Q, sz;
    int type, a, b;
    char* str;
    Node* headList[100001] = {};
    Node* tailList[100001] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &sz);
        str = (char*)malloc((sz + 1) * sizeof(char));
        if (sz > 0) {
            scanf("%s", &str);
            tailList[i] = headList[i] = createNode(str);
        }
    }
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1) {
            if (headList[a] && tailList[b]) {
                tailList[b]->nxt = headList[a];
                headList[a] = headList[b];
            } else if (tailList[b]) {
                headList[a] = headList[b];
                tailList[a] = tailList[b];
            }
            headList[b] = tailList[b] = NULL;
        } else if (type == 2) {
        } else if (type == 3) {
        }
    }
}