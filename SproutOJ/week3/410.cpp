int magic[1505];
void initialize(int n) {
    for (int i = 0; i < n; i++)
        magic[i] = 0;
}
int hasEdge(int a, int b) {
    return magic[a];
}