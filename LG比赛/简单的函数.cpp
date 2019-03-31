#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
ll qpow(ll a , ll b) {
	if (!b) return 1;
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
ll n , k , m , x , y , l;
int main() {
	scanf("%lld" , &n);
	m = (n + 30) / 12 - 2;
	k = n / 2 - 1;
	x = qpow(2 , k);
	if (n & 1) x *= 2;
	y = qpow(4 , m);
	y *= qpow(3 , k - m) % MOD;
	y = (y % MOD * x % MOD) % MOD;
	printf("%lld" , y);
	return 0;
}