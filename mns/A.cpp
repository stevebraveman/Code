#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 998244353
int a[MAXN], b[MAXN], ida[MAXN], idb[MAXN];
struct tree {
	int l, r;
}p[MAXN];
int lseq[MAXN], top, rseq[MAXN], c[MAXN], x, y, n;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
void dfsl(int u) {
	if (!u) return;
	lseq[++top] = u;
	dfsl(p[u].l);
	dfsl(p[u].r);
}
void dfsr(int u) {
	if (!u) return;
	dfsr(p[u].l);
	dfsr(p[u].r);
	rseq[++top] = u;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].l, &p[i].r);
	}
	dfsl(1);
	top = 0;
	dfsr(1);
	for (int i = 1; i <= n; i++) {
		ida[lseq[i]] = n - i + 1;
		idb[rseq[i]] = n - i + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ida[i] <= idb[i]) c[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		x = (x + c[lseq[i]] * qpow(2, n - i)) % MOD;
		y = (y + c[rseq[i]] * qpow(2, n - i)) % MOD;
	}
	printf("%d", (y - x + MOD) % MOD);
}