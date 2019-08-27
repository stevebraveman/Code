#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ll long long
ll n, m, ans;
ll phi[MAXN], g[MAXN], p[MAXN], tot, chk[MAXN];
void seive(ll d) {
	chk[1] = phi[1] = 1;
	for (int i = 2; i <= d; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= d; j++) {
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
	for (int i = 1; i <= d; i++) {
		g[i] = g[i - 1] + phi[i];
	}
}
int main() {
	scanf("%lld%lld", &n, &m);
	if (n > m) std::swap(n, m);
	seive(m);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = std::min(n / (n / l), m / (m / l));
		ans += (g[r] - g[l - 1]) * (n / l) * (m / l);
	}
	printf("%lld", 2 * ans - n * m);
}