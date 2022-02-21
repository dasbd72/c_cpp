#include <bits/stdc++.h>
// #define BLKSIZE 8
using namespace std;
class BIGINT {
   private:
    vector<int> parts;
    static const int BLKSIZE = 8;
    static const int MULT = 100000000;

   public:
    BIGINT() {}
    BIGINT(int num) {
        if (num == 0)
            parts.push_back(0);
        while (num) {
            parts.push_back(num % MULT);
            num /= MULT;
        }
    }
    BIGINT(string num) {
        for (int i = num.length(); i > 0; i -= BLKSIZE) {
            parts.push_back(stoi((i - BLKSIZE > 0 ? num.substr(i - BLKSIZE, BLKSIZE) : num.substr(0, i))));
        }
    }
    ~BIGINT() {}
    friend ostream& operator<<(ostream& os, BIGINT const& bignum) {
        for (auto rit = bignum.parts.rbegin(); rit != bignum.parts.rend(); ++rit) {
            if (rit == bignum.parts.rbegin())
                os << *rit;
            else
                os << setw(BLKSIZE) << setfill('0') << *rit;
        }
        return os;
    }
    BIGINT operator+(BIGINT const& other) {
        BIGINT ret;
        auto itl = parts.begin();
        auto itr = other.parts.begin();
        int carry = 0;
        int value;
        while (itl != parts.end() && itr != other.parts.end()) {
            value = *itl + *itr + carry;
            ret.parts.push_back(value % MULT);
            carry = value / MULT;
            itl++;
            itr++;
        }
        while (itl != parts.end()) {
            value = *itl + carry;
            ret.parts.push_back(value % MULT);
            carry = value / MULT;
            itl++;
        }
        while (itr != other.parts.end()) {
            value = *itr + carry;
            ret.parts.push_back(value % MULT);
            carry = value / MULT;
            itr++;
        }
        return ret;
    }
    BIGINT operator/(int const& other) {
        int carry = 0;
        BIGINT ret = *this;
        for (auto rit = ret.parts.rbegin(); rit != ret.parts.rend(); ++rit) {
            *rit += carry * MULT;
            carry = *rit % other;
            *rit /= other;
        }
        for (auto rit = ret.parts.rbegin(); rit != ret.parts.rend() && *rit == 0; ++rit) {
            if (next(rit) != ret.parts.rend())
                ret.parts.pop_back();
        }
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int N, F, IDX = 1; cin >> N >> F; IDX++) {
        if (N == 0 && F == 0)
            break;
        string cost;
        BIGINT totcost = 0;
        while (N--) {
            cin >> cost;
            totcost = totcost + BIGINT(cost);
        }
        cout << "Bill #" << IDX << " costs " << totcost << ": each friend should pay " << totcost / F << "\n\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H3-3.cpp ; ./a.out <H3-3.in