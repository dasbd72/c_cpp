#include <bits/stdc++.h>
using namespace std;

class player {
    struct card {
        int num;
        card *next;
        card(int num) {
            next = nullptr;
            this->num = num;
        }
    };

   private:
    int joker;
    card *begin;

   public:
    player() {
        joker = 0;
        begin = new card(-1);
    }
    ~player() {
        card *prev = begin;
        while (begin != nullptr) {
            prev = begin;
            begin = begin->next;
            delete prev;
        }
    }
    void setJoker() {
        joker = 1;
    }
    int getJoker() {
        return this->joker;
    }
    // initialize hand cards
    void initialize(int cnt) {
        card *tmp = begin;
        for (int i = 1; i <= cnt; i++) {
            if (joker && i == 1)
                tmp = tmp->next = new card(0);
            else
                tmp = tmp->next = new card(i);
        }
    }
    // draw and remove card at pos
    card *draw(int pos) {
        card *cur = begin, *tmp;
        while (--pos && cur->next->next != nullptr) cur = cur->next;
        tmp = cur->next;
        cur->next = tmp->next;
        if (tmp->num == 0) joker--;
        return tmp;
    }
    // insert the card to pos
    void insert(int pos, card *crd) {
        card *cur = begin;
        while (--pos && cur->next != nullptr) cur = cur->next;
        crd->next = cur->next;
        cur->next = crd;
        if (crd->num == 0) joker++;
        return;
    }
    // print all hand cards
    void print() {
        card *cur = begin->next;
        while (cur) {
            cout << cur->num << ((cur->next == nullptr) ? "" : " ");
            cur = cur->next;
        }
    }
};

int main() {
    int N, M, K, I1, I2;
    player ply[105];
    int cur_ply = 1, nxt_ply;

    cin >> N >> M >> K;  // Read Input
    // Get people with joker
    for (int i = 1, x; i <= K; i++) {
        cin >> x;
        ply[x].setJoker();
    }

    // Initialize hand cards
    for (int i = 1; i <= N; i++) {
        ply[i].initialize(M);
    }

    // Input loop
    while (cin >> I1 >> I2) {
        if (I1 == -1 || I2 == -1) break;                                       // End of input
        nxt_ply = ((cur_ply + 1) % N == 0) ? cur_ply + 1 : (cur_ply + 1) % N;  // Calculate nxt_ply's index
        ply[cur_ply].insert(I2, ply[nxt_ply].draw(I1));                        // Draw from nxt_ply and Insert to cur_ply
        cur_ply = nxt_ply;                                                     // Next player's turn
    }

    // Print hand cards
    for (int i = 1; i <= N; i++) {
        if (ply[i].getJoker() == 0) {
            ply[i].print();
            break;
        }
    }
    cout << "\n";
}
