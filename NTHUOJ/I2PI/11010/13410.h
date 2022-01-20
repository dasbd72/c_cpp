#include <stdio.h>

typedef struct {
    char from[10];
    char to[10];
    int val;
} transaction;

typedef struct {
    transaction t[2];
    int link;
} block;

typedef struct {
    block* block_data[1010];
    int tail;
} block_chain;

// TODO: return the hash value of the given block
int hash(block* b);

// TODO: create a block with the given information and return its address
block* create_block(int currentTail, transaction t[2]);

// TODO: query someone's balance
int query(block_chain* bc, char name[10], int initial_saving);
