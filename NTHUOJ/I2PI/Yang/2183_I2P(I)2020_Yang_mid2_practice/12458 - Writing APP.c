#include <math.h>
#include <stdio.h>
int n, k, dp[1005][1005];
char s[1005];
int pal(int l, int r) {
    if (l > r)
        return 0;
    else if (l == r)
        return 1;
    else if (dp[l][r])
        return dp[l][r];
    else if (s[l] == s[r])
        return dp[l][r] = 2 + pal(l + 1, r - 1);
    return dp[l][r] = max(pal(l + 1, r), pal(l, r - 1));
}
int main() {
    scanf("%d %d %s", &n, &k, &s);
    printf("%s\n", pal(0, n - 1) >= n - k ? "Yes" : "No");
}