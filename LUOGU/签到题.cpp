#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 4000005
#define ll long long
#define MOD 666623333
#define OK puts("OK")
ll p[MAXN], tot, l, r, phi[MAXN], v[MAXN], ans = 0, n;
bool chk[MAXN];
void pr(int m) {
	for (int i = 2; i <= m; i++) {
		if (!chk[i]) p[++tot] = i;
		for (int j = 1; j <= tot && p[j] * i <= m; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int main() {
	scanf("%lld%lld", &l, &r);
	n = sqrt(r);
	pr(n);
	for (int i = 0; i <= r - l; i++) {
		phi[i] = i + l;
		v[i] = i + l;
	}
	for (int i = 1; i <= tot; i++) {
		ll k = l / p[i] * p[i];
		if (k == l) k = k - p[i];
		if (p[i] >= l) k = 0;
		while (k + p[i] <= r) {
			k += p[i];
			phi[k - l] = phi[k - l] / p[i] * (p[i] - 1);
			while (v[k - l] % p[i] == 0) v[k - l] /= p[i];
		}
	}
	for (int i = 0; i <= r - l; i++) {
		if (v[i] >= 2) {
			phi[i] = phi[i] / v[i] * (v[i] - 1);
		}
	}
	for (ll i = l; i <= r; i++) {
		// printf("%lld\n", i);
		ans = (ans + i - phi[i - l]) % MOD;
	}
	printf("%lld", ans);
}