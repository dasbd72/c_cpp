#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class disjoint_set_rank {
    vector<int> parent;
    vector<int> rank;
    // Modified disjoint set
    int num_connected;
    vector<int> size;
    vector<int> colors;
    vector<set<int>> colors_set;

   public:
    disjoint_set_rank(int n, vector<int>& _colors) : parent(n), rank(n), num_connected(n), size(n), colors(_colors), colors_set(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
            size[i] = 1;
            colors_set[i].insert(colors[i]);
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
        num_connected--;                                                      // Reduce by 1
        size[rb] += size[ra];                                                 // Combine size
        colors_set[rb].insert(colors_set[ra].begin(), colors_set[ra].end());  // Combine distinct colors
        colors_set[ra].clear();                                               // Clear hanging set
        return parent[ra] = rb;
    }
    int get_num_connected() {
        return num_connected;
    }
    int get_partial_size(int x) {
        int root = find_root(x);
        return size[root];
    }
    int get_distinct_colors(int x) {
        int root = find_root(x);
        return colors_set[root].size();
    }
};
void solve() {
    int n, m, q, a, u, v, t;
    int a1, a2, a3;
    vector<int> colors;
    vector<pair<int, int>> edges;
    vector<tuple<int, int, int>> queries;

    cin >> n >> m;
    colors.resize(n);
    edges.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> a;
        colors[i] = a;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;  // from 1-based to 0-based
        if (u > v) {
            swap(u, v);  // make u <= v
        }
        edges[i] = make_pair(u, v);
    }
    cin >> q;
    queries.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            u--, v--;  // from 1-based to 0-based
            if (u > v) {
                swap(u, v);  // make u <= v
            }
        } else {
            cin >> u;
            u--;
        }
        queries[i] = make_tuple(t, u, v);
    }

    // Get the final edges
    set<pair<int, int>> full_edges_set(edges.begin(), edges.end());
    for (int i = 0; i < q; i++) {
        auto [t, u, v] = queries[i];
        if (t == 1) {
            full_edges_set.erase(make_pair(u, v));
        }
    }

    // Build disjoint set from final edges
    disjoint_set_rank ds(n, colors);
    for (auto [u, v] : full_edges_set) {
        if (!ds.same(u, v)) {
            ds.union_by_rank(u, v);
        }
    }

    // Perform query from end
    vector<tuple<int, int, int>> answers;
    for (int i = q - 1; i >= 0; i--) {
        auto [t, u, v] = queries[i];
        if (t == 1) {
            if (!ds.same(u, v)) {
                ds.union_by_rank(u, v);
            }
        } else {
            a1 = ds.get_num_connected();
            a2 = ds.get_partial_size(u);
            a3 = ds.get_distinct_colors(u);
            answers.emplace_back(a1, a2, a3);
        }
    }

    // Reverse print answers
    for (auto it = answers.rbegin(); it != answers.rend(); it++) {
        auto [a1, a2, a3] = *it;
        cout << a1 << " " << a2 << " " << a3 << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
