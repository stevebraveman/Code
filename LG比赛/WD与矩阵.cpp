#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 998244353
#define ll long long
long long t, n, m;
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
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		ll ans = qpow(qpow(2, n - 1), m - 1);
		printf("%lld\n", ans % MOD);
	}
}