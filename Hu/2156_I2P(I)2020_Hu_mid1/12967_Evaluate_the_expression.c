#include<stdio.h>
#include<string.h>
#define ll long long
char s[10000];
ll str_to_int(int l, int r)
{
    int len = r - l + 1;
    ll num = 0;
    for(int i = 0; i < len; i++)
    {
        num *= 10;
        num += s[l+i] - '0';
    }
    return num;
}
int main()
{
    scanf("%s", s+1);
    int cof = 1, cofb = 1; //coefficient of the numbers and brackets, for example : if the previous operator is '-', cof = -1.
    ll ans = 0;
    for(int i = 1; i <= strlen(s+1); i++)
    {
        if(s[i] == ')') cofb = 1, i++;

        if(s[i] == '-' && s[i + 1] == '(') cofb = -1, i++; //brackets inside
        else if(s[i] == '+' && s[i + 1] == '(') cofb = 1, i++; 
        else if(s[i] == '(') cofb = 1; //if the first one is bracket
        else if(s[i] == '+') cof = 1; //addition
        else if(s[i] == '-') cof = -1; //substraction
        else if(s[i] <= '9' && s[i] >= '0') //you need to write this condition or break when (s[i]==')' && s[i+1]=='\n')
        {
            int j = i;
            while(s[j+1] <= '9' && s[j+1] >= '0') j++;
            ans += cof * cofb * str_to_int(i, j); // will times -1 if is in a negetive bracket, and will times -1 again when the previous operator is '-'
            i = j;
        }
    }
    printf("%lld\n", ans);
    return 0;
}