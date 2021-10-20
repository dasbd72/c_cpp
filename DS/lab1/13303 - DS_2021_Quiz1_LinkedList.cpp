#include <bits/stdc++.h>
using namespace std;
class Player {
   private:
    int index;
    Player *nxt;

   public:
    friend class PlayerList;
    Player(int idx) : index(idx), nxt(nullptr){};
    ~Player(){};
};

class PlayerList {
   private:
    Player *bombPos;
    int playerCnt;

   public:
    PlayerList() : bombPos(nullptr), playerCnt(0){};
    ~PlayerList(){};
    void set_players(int n) {
        Player *curr = nullptr, *tmp;
        for (int i = 1, idx; i <= n; i++) {
            cin >> idx;
            tmp = new Player(idx);
            if (curr == nullptr) {
                curr = tmp;
                curr->nxt = curr;
            } else {
                tmp->nxt = curr->nxt;
                curr->nxt = tmp;
            }
            curr = tmp;
        }
        playerCnt += n;
        bombPos = curr->nxt;
        return;
    }
    void pass_bomb(unsigned long long j) {
        j %= playerCnt;
        while (j--) {
            bombPos = bombPos->nxt;
        }
        bombPos = this->rm(bombPos);

        playerCnt--;
    }
    void add_player(unsigned long long idx) {
        Player *tmp = new Player(idx);
        tmp->nxt = bombPos->nxt;
        bombPos->nxt = tmp;
        playerCnt++;
        return;
    }
    Player *rm(Player *node) {
        Player *preNode = node;
        node = node->nxt;
        preNode->index = node->index;
        preNode->nxt = node->nxt;
        delete (node);
        return preNode;
    }
    void print() {
        Player *curr = bombPos;
        do {
            cout << curr->index << ((curr->nxt == bombPos) ? "\n" : " ");
            curr = curr->nxt;
        } while (curr != bombPos);
    }
    int getCnt() {
        return playerCnt;
    }
};

int main() {
    PlayerList Game;
    int N, I;
    unsigned long long J;
    cin >> N;
    Game.set_players(N);
    // Game.print();
    while (cin >> I >> J) {
        if (I == -1 && J == -1) break;
        if (I == 1) {
            Game.pass_bomb(J);
        } else if (I == 2) {
            Game.add_player(J);
        }
        // Game.print();
        if (Game.getCnt() <= 1) break;
    }
    Game.print();
    return 0;
}