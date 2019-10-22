#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 998244353
int p[MAXN], n, ans, Cat[MAXN], _Cat[MAXN], las;
char s[MAXN];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int main() {
	scanf("%d", &n);
	Cat[1] = 1;
	for (int i = 2; i <= n; i++) {
		Cat[i] = 1LL * Cat[i - 1] * (4 * i - 2) % MOD * qpow(i + 1, MOD - 2) % MOD;
	}
	scanf("%s", s + 1);
	// ans = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = s[i] - '0';
	}
	las = 0;
	ans = 1;
	p[n + 1] = p[n] ^ 1;
	for (int i = 1; i <= n; i++) {
		if (p[i] != p[i + 1]) {
			ans = 1LL * ans * Cat[i - las] % MOD;
			las = i;
		}
	}
	printf("%d\n", ans);
}