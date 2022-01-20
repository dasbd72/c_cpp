// g++ .\13203.cpp .\13203-f.cpp -o a ; .\a.exe
#include"13203.h"
// #include"function.h"
#include <iostream>
#include <sstream>
using namespace std;
// Base Human class
Human::Human(string n, int m, int ski):name(n),money(m),skill(ski){
    kicked = false;
    cards = 0;
    bets = 0;
}
int Human::get_money(){return money;}
Human::~Human() = default;

// Guard
Guard::Guard(int ski):Human("Guard", 0, ski){}
void Guard::Pay(Human *human){ // Guard pay Player
	if(human->skill > skill) {
		human->money += human->skill - skill;
		money -= human->skill - skill;
	}
}
void Guard::Kick(Human *human, int flag){
	human->kicked = true;
	if(flag == 1) Pay(human);
}
int bankerPay;
// Banker
Banker::Banker(int ski):Human("Banker", 0, ski){}
void Banker::Pay(Human *human){ // Pay guards or player
	if(human->name == "Guard"){
		money -= 100;
		human->money += 100;
	} else {
		bankerPay = human->bets;
		if(human->skill < skill) bankerPay += 10 * human->cards;
		if(human->cards == 21) bankerPay *= 2;
		money -= bankerPay;
		human->money += bankerPay;
	}
}
int Banker::Win(Human *human){ // 
	if(human->cards > 21 && cards > 21) return 2;
	else if(human->cards <= 21 && (cards > 21 || human->cards > cards)) return 0;
	else return 1;
}
void Banker::Draw(){
	cards = 0;
	int x;
	string input;
	// cin.ignore();
	getline(cin, input);
	istringstream ss(input);
	while(ss >> x) cards += x;
}
Banker::~Banker() = default;

// Player
Player::Player(string name, int m, int ski):Human(name, m, ski){}
void Player::Pay(Human *human){
	int cost = bets;
	if(cost >= money) cost = money;
	money -= cost;
	human->money += cost;
}
void Player::Bet(){
	cin >> name >> bets;
}
void Player::Draw(){
	cards = 0;
	int x;
	string input;
	cin.ignore();
	getline(cin, input);
	istringstream ss(input);
	while(ss >> x) cards += x;
}
bool Player::Kicked(){
	return kicked;
}
bool Player::Bankrupt(){
	return money <= 0;
}
bool Player::Cheat(Human *human){
	return bankerPay > 2 * skill; 
}
Player::~Player() = default;
