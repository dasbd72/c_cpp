#include <stdio.h>

int gcd(int a, int b) {
	for(int i = a > b ? b : a; i >= 1; i--) if(a % i == 0 && b % i == 0) return i;
}

int lcm(int a, int b) {
	for(int i = a > b ? a : b; i; i++) if(i % a == 0 && i % b == 0) return i;
}

int power(int a, int b) {
	// your code here
    if(b == 0) return 1;
    int num;
    num = power(a, b-1) * a;
    return num;
}

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", gcd(lcm(power(a, b), c), d));
	printf("%d\n", gcd(power(lcm(a, b), c), d));
    printf("%d\n", lcm(gcd(power(a, b), c), d));
    printf("%d\n", lcm(power(gcd(a, b), c), d));
    printf("%d\n", power(gcd(lcm(a, b), c), d));
    printf("%d\n", power(lcm(gcd(a, b), c), d));
	return 0;
}