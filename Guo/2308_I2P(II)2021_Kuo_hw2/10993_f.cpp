#include<iostream>
#include<cmath>
#include"10993.h"
using namespace std;

Polynomial::Polynomial(){
    greatestPower = 0;
    for(int i = 0; i < 51; i++) coefficients[i] = 0;
}
Polynomial::Polynomial(const int grtPow, const int coef[51]){
    greatestPower = grtPow;
    for(int i = 0; i < 51; i++) coefficients[i] = i <= grtPow ? coef[i] : 0;
}
Polynomial Polynomial::add( const Polynomial poly) const{
    Polynomial newPoly;
    newPoly.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = newPoly.greatestPower; i >= 0; i--){
        newPoly.coefficients[i] = coefficients[i] + poly.coefficients[i];
    }
    for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }
    return newPoly;
}
Polynomial Polynomial::subtract( const Polynomial poly) const{
    Polynomial newPoly;
    newPoly.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = newPoly.greatestPower; i >= 0; i--){
        newPoly.coefficients[i] = coefficients[i] - poly.coefficients[i];
    }
    for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }
    return newPoly;
}
Polynomial Polynomial::multiplication( const Polynomial poly) const{
    Polynomial newPoly;
    newPoly.greatestPower = greatestPower + poly.greatestPower;
    for(int i = 0; i <= greatestPower; i++) for(int j = 0; j <= poly.greatestPower; j++){
        newPoly.coefficients[i + j] += coefficients[i] * poly.coefficients[j];
    }
    for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }
    return newPoly;
}
void Polynomial::output() const{
    for(int i = greatestPower; i >= 0; i--){
        cout << coefficients[i];
        if(i != 0) cout << ' ';
    }
}