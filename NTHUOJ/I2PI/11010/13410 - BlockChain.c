#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"
// #include "13410.h"
int hash(block* b) {
    int sum = b->t[0].val + b->t[1].val;
    return (((sum * sum) ^ b->link) + b->link * b->link) % 1000 + 1;
}

block* create_block(int currentTail, transaction t[2]) {
    block* new_block = (block*)malloc(sizeof(block));
    new_block->link = currentTail;
    for (int i = 0; i < 2; i++) {
        new_block->t[i].val = t[i].val;
        strcpy(new_block->t[i].from, t[i].from);
        strcpy(new_block->t[i].to, t[i].to);
    }
    return new_block;
}

int query(block_chain* bc, char name[10], int initial_saving) {
    int sum = initial_saving;
    int curr = bc->tail;
    while (curr != 0) {
        block* bd = bc->block_data[curr];
        for (int i = 0; i < 2; i++) {
            if (strcmp(bd->t[i].from, name) == 0)
                sum -= bd->t[i].val;
            if (strcmp(bd->t[i].to, name) == 0)
                sum += bd->t[i].val;
        }
        curr = bd->link;
    }
    return sum;
}