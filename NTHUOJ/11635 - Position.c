#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input_str[1000005] = {};    // The input, Start from 1
int last_pos[52] = {};           // Store the first position of A(0)~Z(25) and a(26)~z(51)
int str_next_pos[1000005] = {};  // Next position of the same letter
int input_len;
int main() {
    scanf("%s", input_str + 1);
    input_len = strlen(input_str + 1);

    for (int i = input_len; i >= 1; i--) {
        if (input_str[i] <= 'Z' && input_str[i] >= 'A') {
            str_next_pos[i] = last_pos[input_str[i] - 'A'];
            last_pos[input_str[i] - 'A'] = i;
        } else if (input_str[i] <= 'z' && input_str[i] >= 'a') {
            str_next_pos[i] = last_pos[input_str[i] - 'a' + 26];
            last_pos[input_str[i] - 'a' + 26] = i;
        }
    }
    for (int i = 0; i < 52; i++) {
        if (last_pos[i] == 0) continue;
        if (i <= 25)
            printf("%c:", i + 'A');
        else
            printf("%c:", i - 26 + 'a');

        for (int j = last_pos[i]; j != 0; j = str_next_pos[j]) {
            printf(" %d", j - 1);
        }
        printf("\n");
    }
}