#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 998244353
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
ll n, a, b;
int main() {
	scanf("%lld%lld%lld", &n, &a, &b);
	printf("%lld", (qpow(a, n + 1) + qpow(b, n + 1)) % MOD * qpow((a + b), MOD - 2) % MOD);
	return 0;
}