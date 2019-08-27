#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000010
#define ll long long
ll n, m, p[MAXN], ans, tot, g[MAXN], phi[MAXN], T;
bool chk[MAXN];
void seive(int n) {
	phi[1] = 1;
	for (ll i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (ll j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		g[i] = g[i - 1] + phi[i];
	}
}
int main() {
	scanf("%lld", &T);
	seive(10000000);
	while (T--) {
		ans = 0;
		scanf("%lld", &n);
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			ans += (g[r] - g[l - 1]) * g[n / l];
		}
		printf("%lld\n", 2 * ans - g[n]);
	}
}