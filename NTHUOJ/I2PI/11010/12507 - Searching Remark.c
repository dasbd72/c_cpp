#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define DELIM " \n-/:()[],."
int main() {
    char key[25], str[500], *token;
    int ans;
    ans = 0;
    scanf("%s", key);
    for (int i = 0; i < 25; i++) key[i] = tolower(key[i]);
    while (fgets(str, 500, stdin) != NULL) {
        for (int i = 0; i < 500; i++) str[i] = tolower(str[i]);
        token = strtok(str, DELIM);
        while (token != NULL) {
            if (strcmp(key, token) == 0)
                ans++;
            token = strtok(NULL, DELIM);
        }
    }
    printf("%d\n", ans);
}