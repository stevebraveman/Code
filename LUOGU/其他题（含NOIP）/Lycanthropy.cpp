#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2010000
#define ll long long
ll a[MAXN * 2], n, m, l, r, b[MAXN * 2];
template <typename Tp>
void read(Tp &x) {
	Tp f = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x = x * f;
}
int main() {
	read(n), read(m);
	ll *c = a + 2000100;
	ll *d = b + 2000100;
	for (ll i = 1; i <= n; i++) {
		read(l), read(r);
		c[r - 2 * l + 1] -= 2;
		c[r + 1] += 2;
		c[r + 2 * l + 1] -= 2;
		c[r - 3 * l + 1]++;
		c[r + 3 * l + 1]++;
	}
	for (int i = -100000; i <= m + 100000; i++) {
		c[i] += c[i - 1];
	}
	for (int i = -100000; i <= m + 100000; i++) {
		d[i] += d[i - 1] + c[i];
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}