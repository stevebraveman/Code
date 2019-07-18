#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4000010
#define int long long
int p[MAXN + 10], tot, phi[MAXN + 10], T, g[MAXN + 10], answ;
bool chk[MAXN + 10];
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
void sieve() {
	phi[1] = 1;
	chk[1] = true;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (!(i % p[j])) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * phi[p[j]];
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		g[i] = g[i - 1] + phi[i];
	}
}
int sum(int x, int y) {
	int n = min(x, y);
	int m = max(x, y);
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (n / l) * (m / l) * (g[r] - g[l - 1]);
	}
	return ans;
}
int a, b, c, d, n, m;
signed main() {
	sieve();
	while ("CY AK IOI") {
		scanf("%lld", &c);
		if (c == 0) break;
		answ = sum(c, c);
		printf("%lld\n", (answ - (c) * (c + 1) / 2) / 2);
	}
}