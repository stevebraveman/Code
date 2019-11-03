#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define MAXN 100010
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int c[MAXN], n;
int main() {
	c[0] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		c[i] = 1LL * (1LL * c[i - 1] * (4 * i - 2) % MOD) * qpow(i + 1, MOD - 2) % MOD;
	}
	printf("%d", c[n]);
}