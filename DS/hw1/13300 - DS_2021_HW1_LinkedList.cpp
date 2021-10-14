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
                tmp = this->insert_ptr(tmp, 0);
            else
                tmp = this->insert_ptr(tmp, i);
        }
    }
    // insert num after the card
    card *insert_ptr(card *crd, int num) {
        if (crd == nullptr) {
            cout << "Insert pos nullptr.\n";
            return nullptr;
        }
        card *tmp = new card(num);
        tmp->next = crd->next;
        crd->next = tmp;
        return tmp;
    }
    // draw and remove card at pos
    card *draw(int pos) {
        card *cur = begin, *tmp;
        while (--pos) cur = cur->next;
        tmp = cur->next;
        cur->next = tmp->next;
        return tmp;
    }
    // insert the card to pos
    void insert(int pos, card *crd) {
        card *cur = begin;
        while (--pos) cur = cur->next;
        crd->next = cur->next;
        cur->next = crd;
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

    cin >> N >> M >> K;

    for (int i = 1, x; i <= K; i++) {  // Get people with joker
        cin >> x;
        ply[x].setJoker();
    }

    for (int i = 1; i <= N; i++) {  // Initialize hand cards
        ply[i].initialize(M);
    }

    while (cin >> I1 >> I2) {
        if (I1 == -1 || I2 == -1) break;  // End of input
        nxt_ply = ((cur_ply + 1) % N == 0) ? cur_ply + 1 : (cur_ply + 1) % N;
        ply[cur_ply].insert(I2, ply[nxt_ply].draw(I1));
        cur_ply = nxt_ply;  // Next player's turn
    }

    for (int i = 1; i <= N; i++) {
        if (ply[i].getJoker() == 0) {
            ply[i].print();
            break;
        }
    }
    cout << "\n";
}
