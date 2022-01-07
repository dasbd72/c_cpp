#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

#define SIZE 41

class Hash_table {
   public:
    list<string> table[SIZE];

    virtual void Add(const string &str) = 0;
    virtual void Delete(const string &str) = 0;
    virtual bool Exist(const string &str) = 0;
    friend std::ostream &operator<<(std::ostream &os, const Hash_table &ht) {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (string str : ht.table[i]) {
                cout << str << "->";
            }
            cout << "[END]";
            cout << endl;
        }
        return os;
    }
};

class Implement : public Hash_table {
   public:
    void Add(const string &str);
    void Delete(const string &str);
    bool Exist(const string &str);
};
#endif
