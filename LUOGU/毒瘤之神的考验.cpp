#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 998244353
#define S 35
#define int long long
int p[MAXN], T, phi[MAXN], mu[MAXN], tot, *t[S + 2][S + 2], *g[MAXN], inv[MAXN], f[MAXN], n, ans, m;
bool chk[MAXN];
void seive(int n) {
	chk[1] = 1;
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
				mu[i * p[j]] = -mu[i];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
}
void pre(int n) {
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			f[j] = (f[j] + (1LL * (1LL * (mu[j / i] + MOD) * i % MOD) * inv[phi[i]]) % MOD + MOD) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) {
		g[i] = new int [(n / i) + 1];
		g[i][0] = 0;
		for (int j = 1; j <= n / i; j++) g[i][j] = (g[i][j - 1] + phi[i * j]) % MOD;
	}
	for (int i = 1; i <= S; i++) {
		for (int j = i; j <= S; j++) {
			int l = n / std::max(j, i);
			t[i][j] = new int [l + 1];
			t[i][j][0] = 0;
			for (int k = 1; k <= l; k++) {
				t[i][j][k] = (t[i][j][k - 1] + 1LL * (1LL * f[k] * g[k][i] % MOD) * g[k][j] % MOD);
			}
		}
	}
}
signed main() {
	scanf("%d", &T);
	seive(100000);
	pre(100000);
	while (T--) {
		scanf("%d%d", &n, &m);
		ans = 0;
		if (n > m) std::swap(n, m);
		for (int i = 1; i <= m / S; i++) {
			ans = (ans + 1LL * (1LL * f[i] * g[i][n / i] % MOD) * g[i][m / i] % MOD) % MOD;
		}
		for (int l = m / S + 1, r; l <= n; l = r + 1) {
			r = std::min(n / (n / l), m / (m / l));
			ans = (ans + t[n / l][m / l][r] - t[n / l][m / l][l - 1] + MOD) % MOD;
		}
		printf("%d\n", ans);
	}
}