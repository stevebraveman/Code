#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
#define MAXN 1000010
#define PI acos(-1)
#define cp std::complex <double>
cp a[MAXN], b[MAXN], omg[MAXN], inv[MAXN];
int n = 1, la, lb, res[MAXN], as[MAXN], bs[MAXN];
void init() {
	for (int i = 0; i < n; i++) {
		omg[i] = cp(cos(2 * PI * i / n), sin(2 * PI * i / n));
		inv[i] = conj(omg[i]);
	}
}
void fft(cp *a, cp *omg) {
	int bit = 0;
	while ((1 << bit) < n) bit++;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < bit; j++) {
			if ((i >> j) & 1) t |= (1 << (bit - j - 1));
		}
		if (i < t) swap(a[i], a[t]);
	}
	static cp buf[MAXN];
	for (int l = 2; l <= n; l *= 2) {
		int m = l / 2;
		for (cp *p = a; p != a + n; p += l) {
			for (int i = 0; i < m; i++) {
				cp t = omg[n / l * i] * p[i + m];
				p[i + m] = p[i] - t;
				p[i] += t;
			}
		}
	}
}
int main() {
	scanf("%d%d", &la, &lb);
	for (int i = 0; i < la; i++) {
		scanf("%d", &as[i]);
	}
	for (int i = 0; i < lb; i++) {
		scanf("%d", &bs[i]);
	}
	while (n < la + lb) n *= 2;
	for (int i = 0; i < la; i++) {
		a[i].real(as[la - 1 - i] - '0');
	}
	for (int i = 0; i < lb; i++) {
		b[i].real(bs[lb - 1 - i] - '0');
	}
	init();
	fft(a, omg);
	fft(b, omg);
	for (int i = 0; i < n; i++) {
		a[i] *= b[i];
	}
	fft(a, inv);
	for (int i = 0; i < n; i++) {
		res[i] += floor(a[i].real() / n + 0.5);
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	for (int i = res[la + lb - 1] ? la + lb - 1 : la + lb - 2; i >= 0; i--) {
		printf("%d ", res[i]);
	}
	return 0;
}