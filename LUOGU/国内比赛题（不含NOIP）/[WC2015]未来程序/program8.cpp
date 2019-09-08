#include <stdio.h>
unsigned long long a, b, c, d, e, f, g, n, q, r, s, t, u, v, w, x, y, z;
unsigned long long p = 1234567891;

int main() {
	scanf("%llu", &n);
	a = 0;
	q = 0;
	r = 0;
	s = 0;
	t = 0;
	u = 0;
	v = 0;
	w = 0;
	x = 0;
	y = 0;
	z = 0;
	a = 0;
	while (a < n) {
		a = a + 1;
		b = 0;
		while (b < n) {
			b = b + 1;
			c = 0;
			while (c < n) {
				c = c + 1;
				d = 0;
				while (d < n) {
					d = d + 1;
					e = 0;
					while (e < n) {
						e = e + 1;
						f = 0;
						while (f < n) {
							f = f + 1;
							g = 0;
							while (g < n) {
								g = g + 1;

								if (a < b && b < c && c < d && d < e && e < f && f < g) {
									q = q + 1;
									q = q % p;
								}

								if (a < b && c < g && c < d && e < f && a < d) {
									r = r + 1;
									r = r % p;
								}

								if (a < d && d < f && c < f && c < e && b < d) {
									s = s + 1;
									s = s % p;
								}

								if (d < e && b < d && a < f && d < e && b < g) {
									t = t + 1;
									t = t % p;
								}

								if (c < f && b < f && b < c && f < g && b < f) {
									u = u + 1;
									u = u % p;
								}

								if (b < d && b < c && d < f && c < e && b < e) {
									v = v + 1;
									v = v % p;
								}

								if (a < c && a < b && c < e && b < f && e < g) {
									w = w + 1;
									w = w % p;
								}

								if (b < d && b < f && a < g && c < g && a < e) {
									x = x + 1;
									x = x % p;
								}

								if (b < f && a < c && c < d && a < c && b < e) {
									y = y + 1;
									y = y % p;
								}

								if (d < e && e < f && a < d && c < g && b < d) {
									z = z + 1;
									z = z % p;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%llu\n", q);
	printf("%llu\n", r);
	printf("%llu\n", s);
	printf("%llu\n", t);
	printf("%llu\n", u);
	printf("%llu\n", v);
	printf("%llu\n", w);
	printf("%llu\n", x);
	printf("%llu\n", y);
	printf("%llu\n", z);
	return 0;
}