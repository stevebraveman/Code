#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define MOD 998244353
int a[MAXN], n, m, sta[MAXN][2], sum[MAXN], op, x, y;
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
	scanf("%d%d", &n, &m);
	while (m--) {
		printf("%d", &op);
		if (op == 1) {
			
		}
	}
}