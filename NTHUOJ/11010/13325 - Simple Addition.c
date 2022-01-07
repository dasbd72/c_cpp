#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
    int len, start, ans, num;
    char str[1000];
    while (gets(str)) {
        len = strlen(str);
        if (str[0] == '0' && len == 1)
            break;
        ans = 0;

        start = 0;
        for (int i = 0; i < len + 1; i++) {
            if (!isdigit(str[i])) {
                str[i] = ' ';
                sscanf(str + start, "%d", &num);
                start = i + 1;
                ans += num;
            }
        }
        printf("%d\n", ans);
    }
}