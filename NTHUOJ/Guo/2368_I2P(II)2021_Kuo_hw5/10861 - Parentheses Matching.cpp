#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++) {
        string str;
        bool availible = true;
        stack<char> para;
        getline(cin, str);
        for (auto c : str) {
            if (c == '}' || c == ']' || c == ')' || c == '>') {
                if (para.empty()) {
                    availible = false;
                    break;
                } else if (c == '}') {
                    if (para.top() != '{') {
                        availible = false;
                        break;
                    }
                } else if (c == ']') {
                    if (para.top() != '[') {
                        availible = false;
                        break;
                    }
                } else if (c == ')') {
                    if (para.top() != '(') {
                        availible = false;
                        break;
                    }
                } else if (c == '>') {
                    if (para.top() != '<') {
                        availible = false;
                        break;
                    }
                }
                para.pop();
            } else if (c == '(' || c == '{' || c == '[' || c == '<') {
                para.push(c);
            }
        }
        if (!para.empty()) availible = false;
        cout << "Case " << i << ": " << (availible ? "Yes" : "No") << endl;
    }
}