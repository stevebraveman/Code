#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
ll t , p, m, a, b, yy;
bool flag = 0;
ll readln() {
	char c = getchar();
	ll x = 0;
	while (c > '9' || c < '0') {c = getchar();}
	while (c <= '9' && c >= '0') {x = x * 10 + c - '0';if (x >= yy) {x %= yy, flag = 1;} c = getchar();}
	return x;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b , a % b);
}
ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return res % p;
}
ll phi(ll k) {
	ll x = k;
	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) {
			x = x / i * (i - 1);
			while (k % i == 0) {
				k /= i;
			}
		}
	}
	if (k > 1) {
		x = x / k * (k - 1);
	}
	return x;
}
int main() {
	scanf("%lld%lld", &a, &m);
	yy = phi(m);
	b = readln();
	if (gcd(a, m) == 1) {
		printf("%lld", qpow(a, b, m));
	}
	else {
		if (flag == 0) {
			printf("%lld", qpow(a, b, m));
		}
		else {
			printf("%lld", qpow(a, b + yy, m));
		}
	}
}