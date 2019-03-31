#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int n, m, x, y, t, k, p, q, a, b, c;
int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &t);
	n--, m--, x--, y--;
	k = lcm(m, n) * 2;
	p = lcm(m, n) / m;
	q = lcm(m, n) / n;
	x *= p;
	y *= q;
	a = x + y;
	b = gcd(a, k);
	k /= b;
	a /= b;
	if (t == 1) {
		printf("%d/%d", a, k);
	}
	if (t == 0) {
		printf("%.3f", (double)a / k);
	}
}