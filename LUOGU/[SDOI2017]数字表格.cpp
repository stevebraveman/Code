#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2000100
#define MOD 1000000007
#define ll long long
ll f[MAXN], n, m, mu[MAXN], p[MAXN], tot, g[MAXN], k[MAXN], ans, pr;
bool chk[MAXN];
void seive(ll l) {
	chk[1] = 1;
	mu[1] = 1;
	for (ll i = 2; i <= l; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && p[j] * i <= l; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = mu[i] * mu[p[j]];
			}
			else break;
		}
	}
}
ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return res % m;
}
int T;
ll b = MAXN - 10;
int main() {
	scanf("%d", &T);
	f[1] = 1;
	f[2] = 1;
	g[1] = 1;
	g[2] = 1;
	for (int i = 3; i <= MAXN - 10; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
		g[i] = qpow(f[i], MOD - 2, MOD) % MOD;
		k[i] = 1;
	}
	seive(MAXN - 10);
	k[0] = k[1] = k[2] = 1;
	for (ll i = 1; i <= b; i++) {
		if (!mu[i]) continue;
		for (ll j = i; j <= b; j += i) {
			k[j] = k[j] * (mu[i] == 1 ? f[j / i] : g[j / i]) % MOD;
		}
	}
	for (int i = 2; i <= b; i++) {
		k[i] = k[i] * k[i - 1] % MOD;
	}
	while (T--) {
		scanf("%lld%lld", &n, &m);
		if (n > m) {
			std::swap(n, m);
		}
		ans = 1;
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = std::min(m / (m / l), n / (n / l));
			pr = k[r] * qpow(k[l - 1], MOD - 2, MOD) % MOD;
			ans = ans * qpow(pr, (n / l) * (m / l) % (MOD - 1), MOD) % MOD;
		}
		printf("%lld\n", ans);
	}
}