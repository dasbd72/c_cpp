// AC
#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <cstring>
namespace oj {
    class BigInt {
        char *_val;
    public:
        BigInt(char *s);
        ~BigInt();
        BigInt& operator++();
        BigInt operator++(int);
        BigInt& operator--();
        BigInt operator--(int);
        char* to_s();
    };

    BigInt::BigInt(char *s) {
        _val = new char[strlen(s)+1];
        strcpy(_val, s);
    }
    BigInt::~BigInt() {
        if(_val) delete [] _val;
    }
    BigInt& BigInt::operator++() {
        int i = strlen(_val)-1;
        while(i >= 0){
            _val[i]++;
            if(_val[i] > '9') {
                _val[i] = '0';
                if(i == 0) {
                    char *_oldval = _val;
                    _val = new char[strlen(_oldval)+2];
                    strcpy(_val+1, _oldval);
                    delete [] _oldval;
                    _val[0] = '1';
                }
                i--;
            } else {
                break;
            }
        }
        return (*this);
    }
    BigInt BigInt::operator++(int) {
        BigInt r(_val);
        operator++();
        return r;
    }
    BigInt& BigInt::operator--() {
        if(strlen(_val) == 1 && _val[0] == '0') return (*this);
        int i = strlen(_val)-1;
        while(i >= 0){
            _val[i]--;
            if(_val[i] < '0') {
                _val[i] = '9';
                i--;
            } else {
                break;
            }
        }
        if(_val[0] == '0'){
            if(_val[1] != '\0'){
                char *_oldval = _val;
                _val = new char[strlen(_oldval)];
                strcpy(_val, _oldval + 1);
                delete [] _oldval;
            }
        }
        return (*this);
    }
    BigInt BigInt::operator--(int) {
        BigInt r(_val);
        operator--();
        return r;
    }
    char* BigInt::to_s() {
        return _val;
    }
}  // namespace oj

#endif
