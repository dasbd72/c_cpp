#include <iostream>
#include <sstream>
using namespace std;
int main() {
    string s;
    stringstream ss;
    int num;
    cin >> s;
    int i = 0;
    while (!isdigit(s[i])) {
        i++;
    }
    int j = i;
    while (isdigit(s[j])) {
        j++;
    }
    ss << s.substr(i, j);
    ss >> num;
    cout << stoll(string("-11010")) << endl;
}