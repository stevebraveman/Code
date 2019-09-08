//сука блять
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000001
int m, n, r, T, jc[MAXN], tot, p[MAXN], jc2[MAXN], jc3[MAXN];
bool chk[MAXN];
void seive(int n) {
	chk[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int qpow(int a, int b, int m) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % m;
		b >>= 1;
		a = (1LL * a * a) % m;
	}
	return res % m;
}
int main() {
	scanf("%d%d", &T, &r);
	jc[1] = 1;
	jc2[1] = 1;
	jc3[1] = 1;
	seive(MAXN - 1);
	for (int i = 2; i <= MAXN - 1; i++) {
		if (!chk[i]) {
			jc[i] = 1LL * jc[i - 1] * i % r;
			jc3[i] = 1LL * jc3[i - 1] * (i - 1) % r;
		}
		else {
			jc[i] = jc[i - 1];
			jc3[i] = jc3[i - 1];
		}
		jc2[i] = 1LL * jc2[i - 1] * i % r;
	}
	while (T--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", (int)((1LL * ((1LL * jc2[n] * jc3[m]) % r) * qpow(jc[m], r - 2, r)) % r));
	}
}