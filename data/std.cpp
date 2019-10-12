#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 998244353
inline long long multi(long long x,long long y,long long mod) {
	long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
	return tmp<0 ? tmp+mod : tmp;
}
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = multi(res, a, MOD);
		b >>= 1;
		a = multi(a, a, MOD);
	}
	return res % MOD;
}
ll n, a, b;
int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data7.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &a, &b);
	printf("%lld", multi((qpow(a, n + 1) + qpow(b, n + 1)) % MOD, qpow((a + b), MOD - 2) % MOD, MOD));
	return 0;
}
/*
JSJSJSJSJSJSJSJSJSJS
BSBSBSBSBSBSBSBSBSBS
 */