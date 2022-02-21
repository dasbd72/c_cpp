#include <bits/stdc++.h>
using namespace std;
char getReverse(char c);
bool calcIsPalindrome(string s);
bool calcIsMirror(string s);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (string S; cin >> S;) {
        bool isPalindrome, isMirror;

        isPalindrome = calcIsPalindrome(S);
        isMirror = calcIsMirror(S);

        cout << S << " -- ";
        if (isPalindrome && isMirror)
            cout << "is a mirrored palindrome.";
        else if (isPalindrome && !isMirror)
            cout << "is a regular palindrome.";
        else if (!isPalindrome && isMirror)
            cout << "is a mirrored string.";
        else
            cout << "is not a palindrome.";
        cout << "\n\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H3-0.cpp ; ./a.out <H3-0.in
bool calcIsPalindrome(string s) {
    auto lit = s.begin(), rit = prev(s.end());
    while (lit <= rit) {
        if (*lit != *rit)
            return false;
        lit = next(lit);
        rit = prev(rit);
    }
    return true;
}
bool calcIsMirror(string s) {
    auto lit = s.begin(), rit = prev(s.end());
    while (lit <= rit) {
        if (getReverse(*lit) == 0 || getReverse(*rit) == 0 || getReverse(*lit) != *rit)
            return false;
        lit = next(lit);
        rit = prev(rit);
    }
    return true;
}
char getReverse(char c) {
    switch (c) {
        case 'A':
            return 'A';
            break;
        case 'E':
            return '3';
            break;
        case 'H':
            return 'H';
            break;
        case 'I':
            return 'I';
            break;
        case 'J':
            return 'L';
            break;
        case 'L':
            return 'J';
            break;
        case 'M':
            return 'M';
            break;
        case 'O':
            return 'O';
            break;
        case 'S':
            return '2';
            break;
        case 'T':
            return 'T';
            break;
        case 'U':
            return 'U';
            break;
        case 'V':
            return 'V';
            break;
        case 'W':
            return 'W';
            break;
        case 'X':
            return 'X';
            break;
        case 'Y':
            return 'Y';
            break;
        case 'Z':
            return '5';
            break;
        case '1':
            return '1';
            break;
        case '2':
            return 'S';
            break;
        case '3':
            return 'E';
            break;
        case '5':
            return 'Z';
            break;
        case '8':
            return '8';
            break;
        default:
            return 0;
            break;
    }
}