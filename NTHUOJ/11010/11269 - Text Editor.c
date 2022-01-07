#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];
char stack[MAX_SIZE];
int input_len;
int content_idx;
int stack_idx;

int main() {
    fgets(input, MAX_SIZE, stdin);
    input_len = strlen(input);
    content_idx = 0;
    stack_idx = 0;
    for (int i = 0; i < input_len; i++) {
        if (input[i] == '/') {
            if (input[i + 1] == 'b') {
                i += 9;
                if (content_idx > 0)
                    content_idx--;
            } else if (input[i + 1] == 'n') {
                i += 7;
                content[content_idx++] = '\n';
            } else if (input[i + 1] == 'l') {
                i += 4;
                if (content_idx > 0)
                    stack[stack_idx++] = content[--content_idx];
            } else if (input[i + 1] == 'r') {
                i += 5;
                if (stack_idx > 0)
                    content[content_idx++] = stack[--stack_idx];
            }
        } else {
            content[content_idx++] = input[i];
        }
    }
    while (stack_idx > 0) {
        content[content_idx++] = stack[--stack_idx];
    }

    printf("%s", content);

    return 0;
}