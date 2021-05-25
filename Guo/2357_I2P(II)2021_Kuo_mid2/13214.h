#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

class Human {
   public:
    string name;
    int money;
    int skill;
    int bets;
    int cards;

    /// @Construct name, money, skill
    Human(string n, int m, int ski);

    virtual void Pay(Human *human) {}
    virtual void Bet() {}
    /// @brief Draw cards
    void Draw();
    virtual int Win(Human *human) {}
    virtual bool Bankrupt() {}
    virtual bool Cheat(Human *human) {}
    virtual void Order(Human *banker, Human *server) {}
    /**
	 * @brief Destroy the Human object
	 */
    ~Human();
};

class Guard : public virtual Human {
   public:
    Guard(int ski);
    /**
	 * @brief When the guard has to kick i-th player who is a cheater out, if guard_ski < skii, the guard has to pay (skii - guard_ski) dollars to the i-th player; if guard_ski >= skii, the guard doesn't have to pay. When the guard has to kick a bankrupt player out, the guard doesn't have to pay.
	 * 
	 * @param human 
	 */
    void Pay(Human *human);
};

class Banker : public virtual Human {
   public:
    Banker(int ski);
    /**
	 * @brief If the i-th player wins, the banker has to pay beti dollars to the i-th player. If the i-th player wins and skii < banker_ski, the banker has to pay the i-th player 10 * (the sum of the i-th player's cards) as a bonus. Furthermore, if the i-th player wins and the sum of the i-th player's cards is equal to 21, the banker has to pay 2*(bets + bonus) to the i-th player. (bonus may be equal to 0) For example, if the sum of the i-th player's cards is 21, skii < banker_ski, and beti = 1000, then the banker has to pay (1000+10*21)*2 to the i-th player.
	 * Or pay guard when need to kick.
	 * 
	 * @param human 
	 */
    void Pay(Human *human);
    /**
	 * @brief Check if banker wins player
	 * 
	 * @param human player
	 * @return int 1 wins, 0 loses, -1 draws
	 */
    int Win(Human *human);
    ~Banker();
};

class Server : public virtual Human {
   public:
    Server(int ski);
    ~Server();
};

class Player : public virtual Human {
   public:
    /**
	 * @brief Construct a new Player object
	 * 
	 * @param name 
	 * @param m 
	 * @param ski 
	 */
    Player(string name, int m, int ski);
    /**
	 * @brief Player pays bets
	 * 
	 * @param human 
	 */
    void Pay(Human *human);
    void Bet();
    /**
	 * @brief If player bankrupted
	 * 
	 * @return true 
	 * @return false 
	 */
    bool Bankrupt();
    /**
	 * @brief 3*skii < the amount of money including the bets and the bonus the banker has to pay to the player
	 * 
	 * @param human 
	 * @return true 
	 * @return false 
	 */
    bool Cheat(Human *human);
    /**
	 * @brief 
	 * 
	 * @param banker 
	 * @param server 
	 */
    void Order(Human *banker, Human *server);
    ~Player();
};

class Casino {
   public:
    Casino();
    ~Casino();
    void Enterance(int f, int u);
    void Guest(string s, int m, int ski);
    void TwentyOne();
    void EndDay();
    void Result();

    int fee, U;

    Human *banker, *guard, *server;
    int player_num;
    Human *player[1009];

    int total_income, today_income;
    int blacklist_num;
    string blacklist[100009];
};
