#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5000010
#define re register
inline int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % p;
		b >>= 1;
		a = (1LL * a * a) % p;
	}
	return res % p;
}
template <typename T>
inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
int n, m, p, k, ans, a[MAXN], s[MAXN], inv[MAXN], last = 1;
int main() {
	s[0] = 1;
	read(n);
	read(p);
	read(k);
	// scanf("%lld%lld%lld", &n, &p, &k);
	for (register int i = 1; i <= n; ++i) {
		read(a[i]);
		// scanf("%lld", &a);
		s[i] = (1LL * s[i - 1] * a[i]) % p;
	}
	inv[n] = qpow(s[n], p - 2, p);
	inv[0] = 1;
	for (int i = n; i; i--) {
		inv[i - 1] = (1LL * inv[i] * a[i]) % p;
	}
	for (re int i = 1; i <= n; i++) {
		int t = (1LL * inv[i] * s[i - 1]) % p;
		ans += (1LL * (1LL * k * last) % p * t) % p;
		last = (1LL * k * last) % p;
		ans %= p;
	}
	printf("%d", ans);
	return 0;
}