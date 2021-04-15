#define SWAP(a,b) {a^=b;b^=a;a^=b;}
int min(int a, int b){
    return (a <= b ? a : b);
}
//bubble sort?
void _sort(long long arr[][500], int y, int x, int len){
    for(int i = 0; i < len-1; i++) for(int j = 0; j < len-1-i; j++)
        if(arr[y+j][x+j] > arr[y+j+1][x+j+1]) SWAP(arr[y+j][x+j], arr[y+j+1][x+j+1]);
}
void array2d_sort(int row, int col, long long arr[][500]){
    for(int y = 1; y < row; y++) _sort(arr, y, 0, min(row-y, col));
    _sort(arr, 0, 0, min(col, row));
    for(int x = 1; x < col; x++) _sort(arr, 0, x, min(col-x, row));
}