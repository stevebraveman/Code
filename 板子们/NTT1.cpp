#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4000100
#define G 3
#define MOD 998244353
#define ll long long
ll rev[MAXN];
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
void ntt(ll *a, ll n, ll f) {
	for (int i = 0; i < n; i++) {
		if (i < rev[i]) {
			std::swap(a[i], a[rev[i]]);
		}
	}
	for (int i = 1; i < n; i <<= 1) {
		ll wn = qpow(G, (MOD - 1) / (((ll)i) << 1));
		for (int j = 0; j < n; j += (((ll)i) << 1)) {
			ll w = 1;
			for (int k = 0; k < i; k++, w = w * wn % MOD) {
				ll x = a[j + k], y = w * a[j + k + i] % MOD;
				a[j + k] = (x + y) % MOD;
				a[j + k + i] = (x - y + MOD) % MOD;
			}
		}
	}
	if (f == 1) return;
	ll tmp = qpow(n, MOD - 2);
	std::reverse(a + 1, a + n);
	for (int i = 0; i < n; i++) {
		a[i] = a[i] * tmp % MOD;
	}
}
ll n, a[MAXN], b[MAXN], m;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = (a[i] + MOD) % MOD;
	}
	for (int i = 0; i <= m; i++) {
		scanf("%lld", &b[i]);
		b[i] = (b[i] + MOD) % MOD;
	}
	ll _n = 1, l = 0;
	while (_n < (n + m + 2)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((1LL * i) & 1) << (l - 1));
	}
	ntt(a, _n, 1);
	ntt(b, _n, 1);
	for (int i = 0; i < _n; i++) {
		a[i] = a[i] * b[i] % MOD;
	}
	ntt(a, _n, -1);
	for (int i = 0; i <= n + m; i++) {
		printf("%lld ", a[i]);
	}
}