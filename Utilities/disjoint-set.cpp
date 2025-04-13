#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
    vector<int> parent;

   public:
    disjoint_set(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_root(int x) {
        int px = parent[x];
        if (x == px)
            return x;
        return parent[x] = find_root(px);
    }
    bool same(int a, int b) {
        return find_root(a) == find_root(b);
    }
    int union_basic(int a, int b) {
        return parent[find_root(a)] = find_root(b);
    }
};
class disjoint_set_rank {
    vector<int> parent;
    vector<int> rank;

   public:
    disjoint_set_rank(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find_root(int x) {
        int px = parent[x];
        if (x == px)
            return x;
        return parent[x] = find_root(px);
    }
    bool same(int a, int b) {
        return find_root(a) == find_root(b);
    }
    int union_by_rank(int a, int b) {
        int ra = find_root(a), rb = find_root(b);
        if (rank[ra] > rank[rb])
            swap(ra, rb);
        if (rank[ra] == rank[rb])
            ++rank[rb];
        return parent[ra] = rb;
    }
};