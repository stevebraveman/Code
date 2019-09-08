#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 400010
#define MOD 998244353
#define G 3
#define I 86583718
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int n, m;
int a[MAXN], b[MAXN], f[MAXN], rev[MAXN];
void ntt(int *a, int n, int f) {
	for (int i = 0; i < n; i++) {
		if (1LL * i < rev[i]) {
			std::swap(a[i], a[rev[i]]);
		}
	}
	for (int i = 1; i < n; i <<= 1) {
		int wn = qpow(G, (MOD - 1) / ((long long)i << 1));
		for (int j = 0; j < n; j += ((long long)i << 1)) {
			int w = 1LL;
			for (int k = 0; k < i; ++k, w = 1LL * w * wn % MOD) {
				int x = a[j + k], y = 1LL * w * a[j + k + i] % MOD;
				a[j + k] = (x + y) % MOD, a[j + k + i] = (x - y + MOD) % MOD;
			}
		}
	}
	if (f == 1) return;
	int tmp = qpow(n, MOD - 2);
	std::reverse(a + 1, a + n);
	for (int i = 0; i < n; i++) {
		a[i] = 1LL * a[i] * tmp % MOD;
	}
}
int c[MAXN];
void inv(int d, int *a, int *b) {
	if (d == 1) {
		b[0] = qpow(a[0], MOD - 2);
		return;
	}
	inv((d + 1) >> 1, a, b);
	int l = 0, _n = 1;
	while (_n < (d << 1)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << (l - 1));
	}
	for (int i = 0; i < d; i++) c[i] = a[i];
	for (int i = d; i < _n; i++) c[i] = 0;
	ntt(c, _n, 1);
	ntt(b, _n, 1);
	for (int i = 0; i < _n; i++) {
		b[i] = 1LL * (2 - 1LL * b[i] * c[i] % MOD + MOD) % MOD * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (int i = d; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
void mult(int *a, int *b, int *c, int n) {
	int _n = 1, l = 0;
	while (_n < (n << 1)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((1LL * i) & 1) << (l - 1));
	}
	ntt(a, _n, 1);
	ntt(b, _n, 1);
	for (int i = 0; i < _n; i++) {
		c[i] = 1LL * a[i] * b[i] % MOD;
	}
	ntt(c, _n, -1);
}
int q[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN], E[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
		A[n - i] = a[i];
	}
	for (int i = 0; i <= m; i++) {
		scanf("%d", &q[i]);
		B[m - i] = q[i];
	}
	for (int i = n - m + 2; i <= m; i++) {
		B[i] = 0;
	}
	inv(n - m + 1, B, C);
	mult(C, A, D, n);
	std::reverse(D, D + n - m + 1);
	for (int i = n - m + 1; i <= n; i++) {
		D[i] = 0;
	}
	for (int i = 0; i < n - m + 1; i++) {
		printf("%d ", D[i]);
	}
	puts("");
	mult(D, q, E, n);
	for (int i = 0; i < m; i++) {
		printf("%d ", (a[i] - E[i] + MOD) % MOD);
	}
	return 0;
}