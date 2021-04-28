#include <string>
using namespace std;

class Guest {
public:
	Guest();
	Guest(string s, int m, int ski);
	~Guest();
	string get_name();
	int get_money();
	int get_skill();
	void Win(int m);
	
private:
	string name;
	int money;
	int skill;
};

class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f);
	void GuestEnter(string s, int m, int ski);
	void Win(string s, int m);
	void EndDay();
	void Result();
	
private:
	int fee;
	
	int guest_num;
	Guest *guest[1009];
	
	int income;
	int list_num;
	string blacklist[1009];
};

Guest::Guest(){

}
Guest::Guest(string s, int m, int ski){
	
}

/*
2
Casino 3 1000
Guest Kuo 1000 20000
Win Kuo 100000
Guest Kuo 30 15
Casino 3 30
Guest Yang 1000 30
Win Kuo 1000
Win Yang 100000
*/