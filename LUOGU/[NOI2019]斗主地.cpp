#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 998244353
int a[MAXN], n, m, type, b[MAXN], q;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &type);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {

	}
}