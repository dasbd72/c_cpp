#include<stdio.h>
#include<stdlib.h>
#define MAXN 100 + 5
int operator(int x, int y)
{
    return(x >= y);
}
void merge_sort(int *begin, int *end)
{
    if(end == begin) return;
    int *mid = begin + (end - begin)/2;
    merge_sort(begin, mid);
    merge_sort(mid+1, end);

    int *left = begin, *right = mid+1, *arr = calloc(end-begin+1, sizeof(int)), arridx = 0;
    while(left <= mid || right <= end)
    {
        if(left > mid) *(arr + arridx++) = *right++;
        else if(right > end) *(arr + arridx++) = *left++;
        else if(operator(*left, *right)) *(arr + arridx++) = *left++;
        else *(arr + arridx++) = *right++;
    }
    for(int *it = begin; it <= end; it++, arr++) *it = *arr;
    return;
}
int main()
{
    int n, m, arr[MAXN][MAXN], q;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
    {
        scanf("%d", &arr[i][j]);
        // printf("%d ", arr[i][j]);
        // if(j == m) printf("\b\n");
    }
    scanf("%d", &q);
    while(q--)
    {
        int u, d, l, r, size;
        scanf("%d %d %d %d", &u, &d, &l, &r);
        size = (d-u+1) * (r-l+1);

        int *arr2 = calloc(size, sizeof(int)), arridx = 0;
        for(int i = u; i <= d; i++) for(int j = l; j <= r; j++)
        {
            arr2[arridx++] = arr[i][j];
        }
        merge_sort(arr2, arr2+size-1);
        printf("%d\n", *arr2);
    }
    return 0;
}