#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 1000010
#define ll long long
#define MOD 998244353
#define G 3
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
ll n, m;
ll a[MAXN], b[MAXN], c[MAXN], rev[MAXN];
void ntt(ll *a, ll n, ll f) {
	for (int i = 0; i < n; i++) {
		if (i < rev[i]) {
			std::swap(a[i], a[rev[i]]);
		}
	}
	for (int i = 1; i < n; i <<= 1) {
		ll wn = qpow(G, (MOD - 1) / ((ll)i << 1));
		for (int j = 0; j < n; j += ((ll)i << 1)) {
			ll w(1);
			for (int k = 0; k < i; ++k, w = 1LL * w * wn % MOD) {
				ll x = a[j + k], y = 1LL * w * a[j + k + i] % MOD;
				a[j + k] = (x + y) % MOD, a[j + k + i] = (x - y + MOD) % MOD;
			}
		}
	}
	if (f == 1) return;
	ll tmp = qpow(n, MOD - 2);
	std::reverse(a + 1, a + n);
	for (int i = 0; i < n; i++) {
		a[i] = 1LL * a[i] * tmp % MOD;
	}
}
void solve(ll d, ll *a, ll *b) {
	if (d == 1) {
		b[0] = qpow(a[0], MOD - 2);
		return;
	}
	solve((d + 1) >> 1, a, b);
	ll l = 0, _n = 1;
	while (_n < (d << 1)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((ll)i & 1) << l - 1);
	}
	for (int i = 0; i < d; i++) {
		c[i] = a[i];
	}
	for (int i = d; i < _n; i++) {
		c[i] = 0;
	}
	ntt(c, _n, 1);
	ntt(b, _n, 1);
	for (int i = 0; i < _n; i++) {
		b[i] = 1LL * (2 - 1LL * b[i] * c[i] % MOD + MOD) % MOD * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (int i = d; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
int main() {
	scanf("%lld", &n);
	for (int i = 1; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		a[i] = MOD - a[i];
	}
	a[0] += 1;
	solve(n, a, b);
	for (int i = 0; i < n; i++) {
		printf("%lld ", b[i]);
	}
	return 0;
}