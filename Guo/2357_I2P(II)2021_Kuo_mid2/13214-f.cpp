// g++ -std=c++17 -O2 -lm -g 13214.cpp 13214-f.cpp -o 13214.exe; .\13214.exe;
#include <iostream>
#include <sstream>
#include <string>

#include "13214.h"
// #include "function.h"
using namespace std;

Human::Human(string n, int m, int ski) : name(n), money(m), skill(ski), cards(0), bets(0) {}
void Human::Draw() {
    this->cards = 0;
    int temp = 0;
    string res = "";
    while (res.size() <= 0)
        getline(cin, res);
    stringstream ss(res);
    while (ss >> temp) {
        this->cards += temp;
    }
}
Human::~Human() = default;

/*--------------------Guard--------------------*/

Guard::Guard(int ski) : Human("Guard", 0, ski) {}
void Guard::Pay(Human *human) {
    if (!human->Bankrupt() && skill < human->skill) {
        money -= human->skill - skill;
        human->money += human->skill - skill;
    }
}

/*--------------------Banker--------------------*/

int bankerToPay = 0;
Banker::Banker(int ski) : Human("Banker", 0, ski) {}
void Banker::Pay(Human *human) {
    if (human->name == "Guard") {
        money -= 100;
        human->money += 100;
    } else {
        bankerToPay = human->bets;
        if (human->skill < skill)
            bankerToPay += 10 * (human->cards);
        if (human->cards == 21)
            bankerToPay *= 2;
        money -= bankerToPay;
        human->money += bankerToPay;
    }
}
int Banker::Win(Human *human) {
    if (human->cards > 21 && cards > 21)
        return -1;
    else if (human->cards <= 21 && (cards > 21 || human->cards > cards))
        return 0;
    else if (cards <= 21 && (human->cards > 21 || cards >= human->cards))
        return 1;
}
Banker::~Banker() = default;

/*--------------------Server--------------------*/

Server::Server(int ski) : Human("Server", 0, ski) {}
Server::~Server() = default;

/*--------------------Player--------------------*/

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}
void Player::Pay(Human *human) {
    int amountToPay = bets >= money ? money : bets;
    money -= amountToPay;
    human->money += amountToPay;
}
void Player::Bet() {
    cin >> bets;
}
bool Player::Bankrupt() {
    return (money <= 0);
}
bool Player::Cheat(Human *human) {
    return (3 * skill < bankerToPay);
}
void Player::Order(Human *banker, Human *server) {
    money -= 3000;
    banker->money += 2000;
    server->money += 1000;
}
Player::~Player() = default;

/*--------------------Casino--------------------*/

Casino::Casino() {
    player_num = total_income = today_income = blacklist_num = 0;
    for (int i = 0; i < 1009; i++)
        player[i] = nullptr;
    banker = new Banker(0);
    guard = new Guard(0);
    server = new Server(0);
}
Casino::~Casino() {
    if (banker)
        delete dynamic_cast<Banker *>(banker);
    if (guard)
        delete dynamic_cast<Guard *>(guard);
    if (server)
        delete dynamic_cast<Server *>(server);
    for (int i = 0; i < player_num; i++) {
        if (player[i])
            delete dynamic_cast<Player *>(player[i]);
    }
}
void Casino::Enterance(int f, int u) {
    U = u;
    fee = f;
}
void Casino::Guest(string s, int m, int ski) {
    for (int i = 0; i < blacklist_num; i++)
        if (s == blacklist[i])
            return;
    for (int i = 0; i < player_num; i++)
        if (s == player[i]->name)
            return;
    if (m <= fee) {
        blacklist[blacklist_num++] = s;
        return;
    } else {
        m -= fee;
        today_income += fee;
    }
    player[player_num++] = new Player(s, m, ski);
}

void Casino::TwentyOne() {
    banker->money = guard->money = server->money = 0;

    int K, idx, record[1009];
    string n;
    cin >> banker->skill >> guard->skill >> server->skill;
    cin >> K;
    for (int i = 0; i < 1009; i++)
        record[i] = 0;
    while (K--) {
        cin >> n;
        int flag = 1;
        Player *new_player = new Player(n, 0, 0);
        new_player->Bet();
        new_player->Draw();

        for (int j = 0; j < this->blacklist_num; j++) {
            if (this->blacklist[j] == n) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < this->player_num; j++) {
                if (this->player[j]->name == n) {
                    record[j] = 1;
                    this->player[j]->bets = new_player->bets;
                    this->player[j]->cards = new_player->cards;
                }
            }
        }
        delete new_player;
    }
    banker->Draw();

    for (int i = 0; i < player_num; i++) {
        if (record[i] == 1) {
            if (banker->Win(player[i]) == 0) {
                banker->Pay(player[i]);
                if (player[i]->money > server->skill) {
                    player[i]->Order(banker, server);
                }
                if (player[i]->Cheat(banker)) {
                    guard->Pay(player[i]);
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            } else if (banker->Win(player[i]) == 1) {
                player[i]->Pay(banker);
                if (player[i]->Bankrupt()) {
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            }
        }
    }
    cout << banker->money << ' ' << guard->money << ' ' << server->money << endl;
    for (int i = 0; i < player_num; i++) {
        cout << player[i]->name << ' ' << player[i]->money << endl;
    }
    today_income += banker->money;
}
void Casino::EndDay() {
    if (today_income >= U)
        blacklist_num = 0;
    total_income += today_income;
    today_income = 0;
    for (int i = 0; i < player_num; i++)
        if (player[i]) {
            delete dynamic_cast<Player *>(player[i]);
            player[i] = nullptr;
        }
    player_num = today_income = 0;
}
void Casino::Result() {
    cout << total_income << endl;
    for (int i = 0; i < blacklist_num; i++) {
        cout << blacklist[i] << endl;
    }
}