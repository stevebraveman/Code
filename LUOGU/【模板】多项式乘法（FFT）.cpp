#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 5000010
#define PI acos(-1.0)
int n, m, lim = 1, l, r[MAXN];
struct cp {
	double x, y;
	cp (double _x = 0, double _y = 0) {x = _x, y= _y;}
};
void swap(cp &a, cp &b) {
	cp t = a;
	a = b;
	b = t;
}
cp operator + (cp a, cp b) {
	return (cp){a.x + b.x, a.y + b.y};
}
cp operator - (cp a, cp b) {
	return (cp){a.x - b.x, a.y - b.y};
}
cp operator * (cp a, cp b) {
	return (cp){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
cp a[MAXN], b[MAXN];
void fft(cp *a, int tp) {
	for (int i = 0; i < lim; i++) {
		if (i < r[i]) swap(a[i], a[r[i]]);
	}
	for (int mid = 1; mid < lim; mid <<= 1) {
		cp wn(cos(PI / mid), tp * sin(PI / mid));
		for (int _r = mid << 1, j = 0; j < lim; j += _r) {
			cp w(1, 0);
			for (int k = 0; k < mid; k++, w = w * wn) {
				cp x = a[j + k], y = w * a[j + mid + k];
				a[j + k] = x + y;
				a[j + mid + k] = x - y;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		std::cin >> a[i].x;
	}
	for (int i = 0; i <= m; i++) {
		std::cin >> b[i].x;
	}
	while (lim <= n + m) lim <<= 1, l++;
	for (int i = 0; i < lim; i++) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
	fft(a, 1);
	fft(b, 1);
	for (int i = 0; i <= lim; i++) {
		a[i] = b[i] * a[i];
	}
	fft(a, -1);
	for (int i = 0; i <= n + m; i++) {
		printf("%d ", (int)(a[i].x / lim + 0.5));
	}
	return 0;
}