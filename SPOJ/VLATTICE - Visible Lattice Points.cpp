#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define ll long long
ll a[MAXN], b[MAXN], p[MAXN], mu[MAXN], tot, n, T, ans, g[MAXN];
bool chk[MAXN];
void seive(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && p[j] * i <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = mu[i] * mu[p[j]];
			}
			else {
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		g[i] = g[i - 1] + mu[i];
	}
}
int main() {
	scanf("%lld", &T);
	seive(1000000);
	while (T--) {
		scanf("%lld", &n);
		ans = 0;
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			ans += 3 * (g[r] - g[l - 1]) * (n / l) * (n / l);
			ans += (g[r] - g[l - 1]) * (n / l) * (n / l) * (n / l);
		}
		// for (ll l = 1, r; l <= n; l = r + 1) {
		// 	r = n / (n / l);
			
		// }
		printf("%lld\n", ans + 3);
	}
}