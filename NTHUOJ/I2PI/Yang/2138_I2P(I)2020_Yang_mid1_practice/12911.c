#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int len1, len2, avalible;
        char s1[1005], s2[1005];
        scanf("%s%s", s1,s2);
        len1 = strlen(s1), len2 = strlen(s2);
        for(int i = len1 - len2 >= 0 ? len1 - len2 : 0; i < len1; i++)
        {
            avalible = 1;
            for(int i2 = 0, i1 = i; i1 < len1; i2++, i1++) if(s1[i1] != s2[i2])
            {
                avalible = 0;
                break;
            }
            if(avalible)
            {
                s1[i] = '\0';
                break;
            }
        }
        printf("%s%s\n", s1, s2);
    }
}