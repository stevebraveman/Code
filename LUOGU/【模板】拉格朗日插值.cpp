#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2010
#define ll long long
#define MOD 998244353
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
ll k, a[MAXN], b[MAXN], t, ans;
int n;
int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		t = 1;
		for (int j = 1; j <= n; j++) {
			if (i != j) t = t * (a[i] - a[j] + MOD) % MOD;
		}
		t = qpow(t, MOD - 2);
		for (int j = 1; j <= n; j++) {
			if (i != j) t = t * (k - a[j] + MOD) % MOD;
		}
		t = t * b[i] % MOD;
		ans = (ans + t) % MOD;
	}
	printf("%lld", ans);
	return 0;
}