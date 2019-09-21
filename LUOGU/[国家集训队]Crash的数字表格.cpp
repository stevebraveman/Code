#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000010
#define MOD 20101009
#define ll long long
ll mu[MAXN + 10], p[MAXN + 10], tot, res = 0, n, m, summu[MAXN + 10], k, k2;
bool chk[MAXN + 10];
ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
void getmu() {
	mu[1] = 1;
	chk[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = -mu[i];
			}
			else break;
		}
	}
	for (ll i = 1; i <= MAXN; i++) {
		summu[i] = ((((mu[i] + MOD) % MOD) * i % MOD * i) % MOD + summu[i - 1]) % MOD;
	}
}
ll sum(ll x) {
	return ((x + 1) * x / 2) % MOD;
}
ll fun(ll n, ll m) {
	ll ans = 0;
	if (n > m) std::swap(n, m);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += ((summu[r] - summu[l - 1] + MOD) % MOD) * (sum(n / l) * sum(m / l) % MOD) % MOD;
		ans %= MOD;
	}
	return (ans + MOD) % MOD;
}
int main() {
	scanf("%lld%lld", &n, &m);
	getmu();
	if (n > m) std::swap(n, m);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		res += ((r - l + 1) * (l + r) / 2 % MOD * fun(n / l, m / l) % MOD + MOD) % MOD;
		res %= MOD;
	}
	printf("%lld\n", res);
	return 0;
}