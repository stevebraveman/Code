#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5000010
#define MOD 1000000007
#define ll long long
ll mu[MAXN + 10], p[MAXN + 10], tot, low[MAXN + 10], h[MAXN + 10], k, T, n, m, ans;
bool chk[MAXN + 10];
ll qpow(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b & 1) res = (res % MOD * a) % MOD;
		b >>= 1;
		a = (a % MOD * a) % MOD;
	}
	return res % MOD;
}
void sieve() {
	low[1] = 1;
	h[1] = 1;
	chk[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			h[i] = (qpow(i, k) - 1 + MOD) % MOD;
			low[i] = i;
		}
		for (ll j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) {
				low[i * p[j]] = (low[i] * p[j]) % MOD;
				if (low[i] == i) h[i * p[j]] = (h[i] % MOD * qpow(p[j], k)) % MOD;
				else h[i * p[j]] = (h[i / low[i]] % MOD * h[p[j] * low[i]]) % MOD;
				break;
			}
			h[i * p[j]] = (h[i] % MOD * h[p[j]]) % MOD;
			low[i * p[j]] = p[j] % MOD;
		}
	}
	for (int i = 2; i <= MAXN; i++) {
		h[i] = (h[i] + h[i - 1] + MOD) % MOD;
	}
}
int main() {
	scanf("%lld%lld", &T, &k);
	sieve();
	while (T--) {
		scanf("%lld%lld", &n, &m);
		if (n > m) std::swap(n, m);
		ans = 0;
		for (ll l = 1LL, r; l <= n; l = r + 1) {
			r = std::min(n / (n / l), m / (m / l));
			ans = (ans + ((n / l) * (m / l) % MOD) * (h[r] - h[l - 1] + MOD) % MOD) % MOD;
		}
		printf("%lld\n", ans % MOD);
	}
}
/*
1 2
3 3
 */