#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class myClass{
public:
    int a;
    myClass(const int &num):a{num}{
    }
};
int main(){
    int cards = 0;
	string input;
	stringstream ss;
	cin.ignore();
	while(getline(cin, input, ' ')){
        if(input == "\n") break;
		cards += stoi(input);
	}
    cout << cards << endl;
}