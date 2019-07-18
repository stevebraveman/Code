#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1000010
#define ll long long
#define MOD 1000000007
#define in6 166666668
#define in3 333333336
#define in2 500000004
ll f[MAXN], g1[MAXN], id1[MAXN], id2[MAXN], p[MAXN], pre1[MAXN], pre2[MAXN];
ll w[MAXN], g2[MAXN], cnt;
ll tot, P, n;
bool chk[MAXN];
void seive() {
	for (ll i = 2; i <= P; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			pre1[tot] = (pre1[tot - 1] + 1LL * i) % MOD;
			pre2[tot] = (pre2[tot - 1] + 1LL * i * i) % MOD;
		}
		for (ll j = 1; j <= tot && i * p[j] <= P; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
ll gid(ll x) {
	if (x <= P) return id1[x];
	else return id2[n / x];
}
ll solve(ll x, ll y) {
	if (p[y] >= x) return 0;
	ll k = gid(x);
	ll ans = (g2[k] - g1[k] + MOD - (pre2[y] - pre1[y]) + MOD + MOD) % MOD;
	for (ll i = y + 1; i <= tot && p[i] * p[i] <= x; i++) {
		ll pp = p[i];
		for (ll j = 1; pp <= x; j++, pp = pp * p[i]) {
			ll _x = pp % MOD;
			ans = (ans + _x * (_x - 1) % MOD * (solve(x / pp, i) + (j != 1))) % MOD;
		}
	}
	return ans % MOD;
}
void work() {
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		w[++cnt] = n / l;
		g1[cnt] = w[cnt] % MOD;
		g2[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD * (2 * g1[cnt] + 1) % MOD * in3 % MOD;
		g2[cnt]--;
		g1[cnt] = g1[cnt] * (g1[cnt] + 1) / 2 % MOD - 1;
		if (n / l <= P) id1[n / l] = cnt;
		else id2[r] = cnt;
	}
	for (ll i = 1; i <= tot; i++) {
		for (ll j = 1; j <= cnt && p[i] * p[i] <= w[j]; j++) {
			ll d = w[j] / p[i];
			d = (d <= P ? id1[d] : id2[n / d]);
			g1[j] -= p[i] * (g1[d] - pre1[i - 1] + MOD) % MOD;
			g2[j] -= p[i] * p[i] % MOD * (g2[d] - pre2[i - 1] + MOD) % MOD;
			g1[j] = (g1[j] % MOD + MOD) % MOD;
			g2[j] = (g2[j] % MOD + MOD) % MOD;
		}
	}
}
int main() {
	scanf("%lld", &n);
	P = sqrt(n);
	seive();
	work();
	printf("%lld", (solve(n, 0) + 1) % MOD);
	return 0;
}