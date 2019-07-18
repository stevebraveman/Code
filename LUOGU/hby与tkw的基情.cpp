#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define ll long long
int T;
ll n;
ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return res % p;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		n = (n + 1) / 2;
		printf("%lld\n", (((2 * n - 1) * qpow(26, n + 1, MOD) % MOD - 26 * (qpow(26, n, MOD) - 1) % MOD * qpow(25, MOD - 2, MOD) * 2 % MOD + 26 + MOD) % MOD) * qpow(25, MOD - 2, MOD) % MOD);
	}
}