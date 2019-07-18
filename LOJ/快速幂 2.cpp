#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 5000000
#define ll long long
#define MOD 998244352
ll x, n, p, a[MAXN], sq, sqx;
ll xs[MAXN], xs2[MAXN];
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
	scanf("%lld%lld", &x, &n);
	sq = sqrt(MOD) + 1;
	xs[0] = 1;
	xs2[0] = 1;
	sqx = qpow(x, sq, MOD);
	for (int i = 1; i <= sq + 1; i++) {
		xs[i] = (xs[i - 1] * x) % MOD;
		xs2[i] = (xs2[i - 1] * sqx) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", (xs[a[i] % sq] % MOD) * (xs2[a[i] / sq] % MOD) % MOD);
	}
}