#include <stdlib.h>
typedef struct {
	long long numerator;
	long long denominator;
} Fraction;


Fraction CreateFrac(long long, long long);
void Reduction(Fraction*);
Fraction Add(Fraction, Fraction);
Fraction Sub(Fraction, Fraction);
Fraction Mul(Fraction, Fraction);
Fraction Div(Fraction, Fraction);
int Compare(Fraction, Fraction);
long long GCD(long long, long long);

Fraction CreateFrac(long long a, long long b){
	return (Fraction){
		.numerator = a,
		.denominator = b
	};
}
void Reduction(Fraction* a){
	long long gcd = GCD(a->numerator, a->denominator);
	a->denominator /= gcd;
	a->numerator /= gcd;
}
Fraction Add(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator += b.numerator;
	Reduction(&a);
	return a;
}
Fraction Sub(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator -= b.numerator;
	Reduction(&a);
	return a;
}
Fraction Mul(Fraction a, Fraction b){
	a.numerator *= b.numerator;
	a.denominator *= b.denominator;
	Reduction(&a);
	return a;
}
Fraction Div(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	a.denominator *= b.numerator;
	Reduction(&a);
	return a;
}
int Compare(Fraction a, Fraction b){
	Reduction(&a);
	Reduction(&b);
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	return a.numerator > b.numerator ? 1 : 0;
}
long long GCD(long long a, long long b){
	if(b == 0) return a;
	return GCD(b, a%b);
}