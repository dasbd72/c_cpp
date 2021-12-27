#include <stdio.h>
#include <string.h>
int main() {
    char strA[3005];
    char strB[3005];
    int lenB, lenA;
    int cntB[26] = {0};
    int save[3005] = {}, save_len, save_cnt;
    int times[3005] = {};
    scanf("%s %d %s", strA, &lenB, strB);

    lenA = strlen(strA);
    save_len = 0;
    for (int i = 0; i < lenB; i++) cntB[strB[i] - 'a']++;
    for (int i = 0; i < lenA - lenB + 1; i++) {
        int flag = 1;
        int cntA[26] = {0};
        for (int j = 0; j < lenB; j++) cntA[strA[i + j] - 'a']++;
        for (int j = 0; j < 26; j++) {
            if (cntA[j] != cntB[j]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            save[save_len++] = i;
    }
    save_cnt = save_len;

    for (int i = 0; i < save_len; i++) {
        if (save[i] == -1)
            continue;
        else
            times[i]++;
        for (int j = i + 1; j < save_len; j++) {
            int flag = 1;
            for (int k = 0; k < lenB; k++) {
                if (strA[save[i] + k] != strA[save[j] + k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                times[i]++;
                save[j] = -1;
                save_cnt--;
            }
        }
    }

    for (int i = 0; i < save_len - 1; i++) {
        for (int j = 0; j < save_len - i - 1; j++) {
            int flag = 0, tmp;
            if (save[j] == -1 || times[j] < times[j + 1])
                flag = 1;
            else if (times[j] == times[j + 1])
                for (int k = 0; k < lenB; k++) {
                    if (strA[save[j] + k] < strA[save[j + 1] + k])
                        break;
                    else if (strA[save[j] + k] > strA[save[j + 1] + k]) {
                        flag = 1;
                        break;
                    }
                }
            if (flag) {
                tmp = save[j];
                save[j] = save[j + 1];
                save[j + 1] = tmp;
                tmp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = tmp;
            }
        }
    }
    printf("%d\n", save_cnt);
    for (int i = 0; i < save_cnt; i++) {
        for (int j = 0; j < lenB; j++) {
            printf("%c", strA[save[i] + j]);
        }
        printf(" %d\n", times[i]);
    }
}