#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
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
int fl, tt[MAXN], rr[MAXN], gg[MAXN], pp[MAXN], kk[MAXN], ss[MAXN], yy[MAXN], hh[MAXN], ww[MAXN];
void clear() {
	for (int i = 1; i < (n << 2); i++) {
		b[i] = c[i] = h[i] = g[i] = d[i] = e[i] = 0;
		tt[i] = rr[i] = kk[i] = ss[i] = yy[i] = hh[i] = 0;
	}
}
void _clr() {
	for (int i = 1; i < (n << 2); i++) {
		ww[i] = pp[i] = gg[i] = tt[i] = rr[i] = kk[i] = ss[i] = yy[i] = hh[i] = 0;
	}
}
void sqrt(int *a, int *b, int d) {
	clear();
	Ln(a, kk, d);
	int inv2 = qpow(2, MOD - 2);
	for (int i = 0; i < d; i++) {
		kk[i] = (1LL * kk[i] * inv2) % MOD;
	}
	clear();
	Exp(kk, b, d);
}
void pow(int *a, int *b, int k, int d) {
	clear();
	_clr();
	Ln(a, kk, n);
	clear();
	for (int i = 0; i < d; i++) {
		kk[i] = 1LL * kk[i] * k % MOD;
	}
	Exp(kk, b, d);
	return;
}
void sin(int *a, int *b, int d) {
	clear();
	_clr();
	for (int i = 0; i < d; i++) {
		tt[i] = 1LL * a[i] * I % MOD;
	}
	Exp(tt, rr, d);
	clear();
	inv(d, rr, gg);
	for (int i = 0; i < d; i++) {
		b[i] = 1LL * (rr[i] - gg[i] + MOD) * qpow(I * 2, MOD - 2) % MOD;
	}
}
void cos(int *a, int *b, int d) {
	clear();
	_clr();
	for (int i = 0; i < d; i++) {
		tt[i] = 1LL * a[i] * I % MOD;
	}
	Exp(tt, rr, d);
	clear();
	inv(d, rr, gg);
	for (int i = 0; i < d; i++) {
		b[i] = 1LL * (rr[i] + gg[i]) * qpow(2, MOD - 2) % MOD;
	}
}
void arcsin(int *a, int *b, int d) {
	clear();
	_clr();
	for (int i = 0; i < d; i++) {
		ww[i] = gg[i] = a[i];
	}
	Deriv(a, tt, d);
	mult(gg, ww, pp, d);
	for (int i = 0; i < d; i++) {
		pp[i] = (MOD - pp[i]) % MOD;
	}
	pp[0] = (pp[0] + 1) % MOD;
	sqrt(pp, ss, d);
	clear();
	inv(d, ss, yy);
	clear();
	mult(tt, yy, hh, d);
	clear();
	Integ(hh, b, d);
}
void arctan(int *a, int *b, int d) {
	clear();
	_clr();
	for (int i = 0; i < d; i++) {
		ww[i] = gg[i] = a[i];
	}
	Deriv(a, tt, d);
	mult(gg, ww, pp, d);
	pp[0] = (1 + pp[0]) % MOD;
	clear();
	inv(d, pp, yy);
	clear();
	mult(tt, yy, hh, d);
	clear();
	Integ(hh, b, d);
}
int q[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN], E[MAXN], F[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	// freopen("data.in", "r", stdin);
	// freopen("data1.out", "w", stdout);
#endif
	clock_t t1;
	t1 = clock();
	read(n), read(m);
	for (int i = 0; i <= n; i++) {
		read(a[i]);
		A[n - i] = a[i];
	}
	for (int i = 0; i <= m; i++) {
		read(q[i]);
		B[m - i] = q[i];
	}
	for (int i = n - m + 2; i <= m; i++) {
		B[i] = 0;
	}
	inv(n - m + 1, B, C);
	clear();
	mult(C, A, D, m + n + 2);
	std::reverse(D, D + n - m + 1);
	for (int i = 0; i < n - m + 1; i++) {
		printf("%d ", D[i]);
	}
	puts("");
	for (int i = n - m + 1; i <= (n << 2); i++) {
		D[i] = 0;
	}
	clear();
	mult(D, q, E, n + 1);
	for (int i = 0; i < m; i++) {
		printf("%d ", (a[i] - E[i] + MOD) % MOD);
	}
	clock_t t2;
	t2 = clock();
	// fclose(stdin);
	// fclose(stdout);
#ifndef ONLINE_JUDGE
	puts("");
	printf("%.2f", (1.0) * (t2 - t1) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}