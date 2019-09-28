#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000000007
ll n;
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
int main() {
	scanf("%lld", &n);
	if (n == 1) {
		puts("1");
		return 0;
	}
	printf("%lld", qpow(3, n - 2 - 2 * ((n - 1) / 3)) % MOD * qpow(2, 2 - (n - 1) % 3) % MOD);
	return 0;
}