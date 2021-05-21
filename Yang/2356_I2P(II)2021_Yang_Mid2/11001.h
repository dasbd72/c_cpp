#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

using namespace std;
class Polynomial
{
    friend std::ostream &operator<<(std::ostream & os, const Polynomial &);
    
public:
    Polynomial(){
        greatestPower=0;
        for(int i =0 ; i< 101 ; i++){
            coefficients[i]=0;
        }
    }
    Polynomial(const int &, const int [51]);
    Polynomial operator+( const Polynomial & ) const; // addition
    Polynomial operator-( const Polynomial & ) const; // subtraction
    Polynomial operator*( const Polynomial & b) const{
        int g = greatestPower+b.greatestPower;
        Polynomial ans ;
        ans.greatestPower=g ;
        for(int i =0 ; i<= g ; i++){
            for(int k =0 ; k<= i ;k++){
                ans.coefficients[i]+=coefficients[k]*b.coefficients[i-k];
            }
        }
        return  ans;
    } // multiplication function
private:
    int coefficients[101];
    int greatestPower;
}; // end class Polynomial

#endif

std::ostream &operator<<(std::ostream & os, const Polynomial &poly){
    for(int i = poly.greatestPower; i >= 0 ; i--) os << poly.coefficients[i] << (i==0?"":" ");  
    return os;
}
Polynomial::Polynomial(const int &gp, const int coef[51]){
    this->greatestPower = gp;
    for(int i = 0; i < 101; i++){
        if(i <= gp) this->coefficients[i] = coef[i];
        else this->coefficients[i] = 0;
    }
}
Polynomial Polynomial::operator+( const Polynomial & poly2) const {
    Polynomial ans;
    ans.greatestPower = this->greatestPower >= poly2.greatestPower ? this->greatestPower : poly2.greatestPower;
    for(int i = 0, j = 0; i <= this->greatestPower || j <= poly2.greatestPower; i++, j++){
        if(i <= this->greatestPower && j <= poly2.greatestPower)
            ans.coefficients[i] = this->coefficients[i] + poly2.coefficients[j];
        else if(i <= this->greatestPower)
            ans.coefficients[i] = this->coefficients[i];
        else
            ans.coefficients[i] = poly2.coefficients[j];
    }
    for(int i = ans.greatestPower; i > 0 && ans.coefficients[i] == 0; i--){
        ans.greatestPower--;
    }
    return ans;
}
Polynomial Polynomial::operator-( const Polynomial & poly2) const {
    Polynomial poly2cpy(poly2.greatestPower, poly2.coefficients);
    for(int i = 0; i <= poly2cpy.greatestPower; i++) poly2cpy.coefficients[i] *= -1;
    return (*this) + poly2cpy;
}