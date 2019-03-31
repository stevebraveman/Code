#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 50010
int chk[MAXN], mu[MAXN], p[MAXN], tot, g[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void read(int &x) {
	char c = getchar();
	int f = 1;
	x = 0;
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0';c = getchar();}
	x = x * f;
}
void mobius() {
	mu[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = -mu[i];
			}
			else break;
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		g[i] = g[i - 1] + mu[i];
	}
}
int T, n, m, l, r, k, nex, ans = 0;
int main() {
	mobius();
	read(T);
	while (T--) {
		read(n), read(m), read(k);
		n /= k;
		m /= k;
		nex = min(n, m);
		ans = 0;
		for (l = 1; l <= nex; l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			ans += (n / l) * (m / l) * (g[r] - g[l - 1]);
		}
		printf("%d\n", ans);
	}
}