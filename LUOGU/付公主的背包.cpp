#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 400010
#define MOD 998244353
#define G 3
#define I 86583718
void read(int &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
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
		b[i] = (2 - 1LL * b[i] * c[i] % MOD + MOD) % MOD * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (int i = d; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
int d[MAXN], e[MAXN];
void Deriv(int *a, int *b, int l) {
	for (int i = 1; i < l; i++) {
		b[i - 1] = 1LL * a[i] * i % MOD;
	}
	b[l - 1] = 0;
}
void Integ(int *a, int *b, int l) {
	for (int i = 1; i < l; i++) {
		b[i] = 1LL * a[i - 1] * qpow(i, MOD - 2) % MOD;
	}
	b[0] = 0;
}
void Ln(int *a, int *b, int k) {
	for (int i = 0; i < 2 * k; i++) d[i] = 0;
	inv(k, a, d);
	Deriv(a, e, k);
	int l = 0, _n = 1;
	while (_n < (k << 1)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << (l - 1));
	}
	ntt(e, _n, 1);
	ntt(d, _n, 1);
	for (int i = 0; i < _n; i++) {
		e[i] = 1LL * e[i] * d[i] % MOD;
	}
	ntt(e, _n, -1);
	Integ(e, b, k);
}
int g[MAXN], h[MAXN];
void Exp(int *a, int *b, int k) {
	if (k == 1) {
		b[0] = 1;
		return;
	}
	Exp(a, b, (k + 1) >> 1);
	int l = 0, _n = 1;
	while (_n < (k << 1)) _n <<= 1, l++;
	for (int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << (l - 1));
	}
	for (int i = 0; i < (k << 1); i++) g[i] = h[i] = 0;
	Ln(b, g, k);
	for (int i = 0; i < k; i++) h[i] = a[i];
	ntt(b, _n, 1);
	ntt(h, _n, 1);
	ntt(g, _n, 1);
	for (int i = 0; i < _n; i++) {
		b[i] = 1LL * (1LL - g[i] + h[i] + MOD) * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (int i = k; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
void clear() {
	for (int i = 1; i < (n << 2); i++) {
		b[i] = c[i] = h[i] = g[i] = d[i] = e[i] = 0;
	}
}
int A[MAXN], B[MAXN], C[MAXN], F[MAXN], x, len;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		A[x]++;
	}
	for (len = 1; len <= m; len <<= 1);
	for (int i = 1; i <= m; i++) {
		if (A[i]) {
			for (int j = i; j <= m; j += i) {
				B[j] = (B[j] + 1LL * A[i] * qpow(j / i, MOD - 2) % MOD) % MOD;
			}
		}
	}
	Exp(B, C, len);
	clear();
	// inv(m, C, F);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", C[i]);
	}
}