#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 500010
int chk[MAXN], mu[MAXN], p[MAXN], tot, g[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void mobius() {
	mu[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
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
	for (int i = 1; i <= MAXN; i++) {
		g[i] = g[i - 1] + mu[i];
	}
}
int T, n, m, k, a, b;
int fun(int n, int m) {
	int nex = min(n, m);
	int ans = 0;
	for (int l = 1, r; l <= nex; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (n / (l * k)) * (m / (l * k)) * (g[r] - g[l - 1]);
	}
	return ans;
}
int main() {
	mobius();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
		printf("%d\n", fun(b, m) + fun(n - 1, a - 1) - fun(n - 1, b) - fun(a - 1, m));
	}
}