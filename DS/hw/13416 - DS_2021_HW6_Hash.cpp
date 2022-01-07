#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "13416.h"
// #include "function.h"

#define MOD 41
#define BASE (13331 % 41)

using namespace std;

int hash_function(const string &str) {
    int sum = 0;
    for (int i = 0, base = 1; i < str.length(); i++, base = (base * BASE) % MOD) {
        sum = (sum + ((str[str.length() - i - 1] % MOD) * base) % MOD) % MOD;
    }
    return sum;
}

void Implement::Add(const string &str) {
    if (!this->Exist(str))
        table[hash_function(str)].push_back(str);
}
void Implement::Delete(const string &str) {
    if (this->Exist(str))
        table[hash_function(str)].remove(str);
}
bool Implement::Exist(const string &str) {
    int hv = hash_function(str);
    return find(table[hv].begin(), table[hv].end(), str) != table[hv].end();
}