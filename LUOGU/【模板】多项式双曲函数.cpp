#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 262150
#define L 262144
#define MOD 998244353
#define G 3
#define re register
template <typename T>
inline void rd(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c <= '9' && c >= '0') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
int s[30], top, Inv[MAXN], rt[MAXN], irt[MAXN];
template <typename T>
void wt(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) wt(x / 10);
	putchar(x % 10 + '0');
}
inline int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = ((long long)res * a) % MOD;
		b >>= 1;
		a = ((long long)a * a) % MOD;
	}
	return res % MOD;
}
inline void init(){
	Inv[1] = 1;
	for(int i = 2; i <= L; i++){
		Inv[i] = (long long)(MOD - MOD / i) * Inv[MOD % i] % MOD;
	}
	rt[0] = irt[0] = 1;
	rt[1] = qpow(3, (MOD - 1) / L);
	irt[1] = qpow(Inv[3], (MOD - 1) / L);
	for(int i = 2; i <= L; ++i){
		rt[i] = (long long)rt[i - 1] * rt[1] % MOD;
		irt[i] = (long long)irt[i - 1] * irt[1] % MOD;
	}
}
int n, m, inv2;
int a[MAXN], b[MAXN], rev[MAXN];
inline void ntt(int *a, int n, int f) {
	for (re int i = 0; i < n; i++) {
		if (i < rev[i]) {
			std::swap(a[i], a[rev[i]]);
		}
	}
	int l = L >> 1;
	for (re int i = 1; i < n; i <<= 1) {
		for (re int j = 0; j < n; j += ((long long)i << 1)) {
			for (re int k = 0; k < i; ++k) {
				int w = (f == 1) ? rt[l * k] : irt[l * k];
				int x = a[j + k], y = (long long)w * a[j + k + i] % MOD;
				a[j + k] = (x + y) % MOD, a[j + k + i] = (x - y + MOD) % MOD;
			}
		}
		l >>= 1;
	}
	if (f == 1) return;
	int tmp = Inv[n];
	// std::reverse(a + 1, a + n);
	for (re int i = 0; i < n; i++) {
		a[i] = (long long)a[i] * tmp % MOD;
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
	for (re int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << l - 1);
	}
	for (re int i = 0; i < d; i++) c[i] = a[i];
	for (re int i = d; i < _n; i++) c[i] = 0;
	ntt(c, _n, 1);
	ntt(b, _n, 1);
	for (re int i = 0; i < _n; i++) {
		b[i] = (long long)((2LL - (long long)b[i] * c[i] % MOD + MOD) % MOD) * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (re int i = d; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
int d[MAXN], e[MAXN];
inline void Deriv(int *a, int *b, int l) {
	for (re int i = 1; i < l; i++) {
		b[i - 1] = (long long)a[i] * i % MOD;
	}
	b[l - 1] = 0;
}
inline void Integ(int *a, int *b, int l) {
	for (re int i = 1; i < l; i++) {
		b[i] = (long long)a[i - 1] * qpow(i, MOD - 2) % MOD;
	}
	b[0] = 0;
}
inline void Ln(int *a, int *b, int k) {
	for (re int i = 0; i < 2 * k; i++) d[i] = 0;
	inv(k, a, d);
	Deriv(a, e, k);
	int l = 0, _n = 1;
	while (_n < (k << 1)) _n <<= 1, l++;
	for (re int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << l - 1);
	}
	ntt(e, _n, 1);
	ntt(d, _n, 1);
	for (re int i = 0; i < _n; i++) {
		e[i] = (long long)e[i] * d[i] % MOD;
	}
	ntt(e, _n, -1);
	Integ(e, b, k);
}
int g[MAXN], h[MAXN];
int er, la, y, _a, iinv;
void Exp(int *a, int *b, int k) {
	if (k == 1) {
		b[0] = 1;
		return;
	}
	Exp(a, b, (k + 1) >> 1);
	int l = 0, _n = 1;
	while (_n < (k << 1)) _n <<= 1, l++;
	for (re int i = 1; i < _n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | (((long long)i & 1) << (l - 1));
	}
	for (re int i = 0; i < (k << 1); i++) g[i] = h[i] = 0;
	Ln(b, g, k);
	for (re int i = 0; i < k; i++) h[i] = a[i];
	ntt(b, _n, 1);
	ntt(h, _n, 1);
	ntt(g, _n, 1);
	for (re int i = 0; i < _n; i++) {
		b[i] = (long long)(1LL - g[i] + h[i] + MOD) * b[i] % MOD;
	}
	ntt(b, _n, -1);
	for (int i = k; i < _n; i++) {
		b[i] = 0;
	}
	return;
}
int A[MAXN], B[MAXN], C[MAXN], t, D[MAXN], E[MAXN], F[MAXN];
int main() {
	init();
	rd(n), rd(t);
	for (int i = 0; i < n; i++) {
		rd(a[i]);
	}
	Exp(a, A, n);
	for (int i = 0; i < MAXN; i++) {
		c[i] = 0;
	}
	inv(n, A, B);
	iinv = Inv[2];
	for (int i = 0; i < n; i++) {
		D[i] = (A[i] + B[i]) % MOD;
	}
	if ((t & 1) == 1) {
		for (int i = 0; i < n; i++) {
			C[i] = (long long)((A[i] - B[i] + MOD) % MOD) * iinv % MOD;
			wt(C[i]), putchar(' ');
		}
		puts("");
	}
	if ((t & 2) == 2) {
		for (int i = 0; i < n; i++) {
			F[i] = (long long)D[i] * iinv % MOD;
			wt(F[i]), putchar(' ');
		}
		puts("");
	}
	if ((t & 4) == 4) {
		for (int i = 0; i < MAXN; i++) {
			c[i] = 0;
		}
		inv(n, D, E);
		for (int i = 0; i < n; i++) {
			wt((E[i] << 1) % MOD), putchar(' ');
		}
	}
	return 0;
}