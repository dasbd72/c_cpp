#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    node() {
        id = 0;
        prev = next = NULL;
    }
    int id;
    node *prev;
    node *next;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node *> heads_ptr(n + 1), tails_ptr(n + 1), ptr(n + 1);
    node nodes[n + 1], heads[n + 1], tails[n + 1];
    for (int i = 1; i <= n; i++) {
        ptr[i] = &nodes[i];
        ptr[i]->id = i;
        ptr[i]->next = tails_ptr[i] = &tails[i];
        ptr[i]->prev = heads_ptr[i] = &heads[i];
        tails_ptr[i]->prev = ptr[i];
        heads_ptr[i]->next = ptr[i];
    }
    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            ptr[a]->prev->next = ptr[a]->next;
            ptr[a]->next->prev = ptr[a]->prev;
            ptr[a]->next = ptr[b]->next;
            ptr[a]->prev = ptr[b];
            ptr[b]->next->prev = ptr[a];
            ptr[b]->next = ptr[a];
        } else {
            if (heads_ptr[a]->next != tails_ptr[a]) {
                heads_ptr[a]->next->prev = tails_ptr[b]->prev;
                tails_ptr[a]->prev->next = tails_ptr[b];
                tails_ptr[b]->prev->next = heads_ptr[a]->next;
                tails_ptr[b]->prev = tails_ptr[a]->prev;

                heads_ptr[a]->next = tails_ptr[a];
                tails_ptr[a]->prev = heads_ptr[a];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":";
        node *curr = heads_ptr[i]->next;
        while (curr != tails_ptr[i]) {
            cout << " " << curr->id;
            curr = curr->next;
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
