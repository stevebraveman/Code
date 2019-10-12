#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAXN 1000005
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
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
char S[MAXN];
int fc[MAXN], ifc[MAXN];
int n, tot, cnt, tr[MAXN][26], ans, m, sum[MAXN], fl[MAXN], fa[MAXN];
inline void ins() {
	scanf("%s", S + 1);
	int len = strlen(S + 1);
	int p = 0;
	for (int i = 1;i <= len;i++) {
		int k = S[i] - 'a';
		if (!tr[p][k]) {
			tr[p][k] = ++cnt;
			fa[cnt] = p;
		}
		p = tr[p][k];
		sum[p]++;
	}
	fl[p] = 1;
}
inline int mch(int pos) {
	int nw = 0;
	tot = 0;
	for (int i = pos; i > 0; ++i) {
		int k = S[i] - 'a';
		if (fl[nw]) return i;
		for (int j = 0; j < k; ++j)
			tot += sum[tr[nw][j]];
		nw = tr[nw][k];
		sum[nw]--;
	}
	return 0;
}
inline int A(int n, int m) {
	if (m > n) return 0;
	return (1ll * fc[n] * ifc[n - m]) % MOD;
}
int main() {
	scanf("%d%d", &n, &m);
	fc[0] = ifc[0] = 1;
	for (int i = 1; i <= n; i++) {
		fc[i] = (1ll * fc[i - 1] * i) % MOD;
	}
	ifc[n] = qpow(fc[n], MOD - 2);
	for (int i = n - 1; i; --i) {
		ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		ins();
	}
	scanf("%s", S + 1);
	int len = 1, nw = 1;
	for (int i = 1; i <= m; i++) {
		nw = mch(nw);
		ans = (ans + 1ll * tot * A(n - i, m - i) % MOD) % MOD;
	}
	printf("%d\n", (ans + 1) % MOD);
	return 0;
}