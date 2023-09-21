#include <bits/stdc++.h>
using namespace std;
struct Node {
    int idx;
    Node *next_node;
    Node *prev_node;
    Node(int idx) : idx(idx), next_node(NULL), prev_node(NULL) {}
};
void solve() {
    int N, M;
    cin >> N >> M;
    vector<Node *> nodes(N + 1);
    vector<Node *> head(N + 1);
    vector<Node *> tail(N + 1);
    for (int i = 1; i <= N; i++) {
        nodes[i] = new Node(i);
        head[i] = new Node(-1);
        tail[i] = new Node(-1);
        head[i]->next_node = nodes[i];
        nodes[i]->prev_node = head[i];
        nodes[i]->next_node = tail[i];
        tail[i]->prev_node = nodes[i];
    }
    while (M--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            if(nodes[a]->prev_node == nodes[b])
                continue;
            Node *apn = nodes[a]->prev_node;
            Node *ann = nodes[a]->next_node;
            Node *bnn = nodes[b]->next_node;
            apn->next_node = ann;
            ann->prev_node = apn;
            nodes[a]->next_node = bnn;
            bnn->prev_node = nodes[a];
            nodes[b]->next_node = nodes[a];
            nodes[a]->prev_node = nodes[b];
        } else {
            if (head[a]->next_node == tail[a]) {
                continue;
            }
            Node *a0 = head[a]->next_node;
            Node *a1 = tail[a]->prev_node;
            Node *b0 = tail[b]->prev_node;
            Node *b1 = tail[b];
            b0->next_node = a0;
            a0->prev_node = b0;
            a1->next_node = b1;
            b1->prev_node = a1;
            head[a]->next_node = tail[a];
            tail[a]->prev_node = head[a];
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << "#" << i << ":";
        Node *cur_node = head[i]->next_node;
        while (cur_node != tail[i]) {
            cout << " " << cur_node->idx;
            cur_node = cur_node->next_node;
        }
        cout << "\n";
    }
    // for (int i = 1; i <= N; i++) {
    //     Node *cur_node = head[i], *prev_node = NULL;
    //     while(cur_node != NULL) {
    //         if(prev_node)
    //             delete prev_node;
    //         prev_node = cur_node;
    //         cur_node = cur_node->next_node;
    //     }
    //     if(prev_node)
    //         delete prev_node;
    // }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2