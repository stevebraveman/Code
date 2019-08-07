#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define MOD 19260817
struct que {
	int l, r, id;
}q[MAXN];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int b[MAXN], a[MAXN], tot, p[MAXN], ctot;
bool chk[MAXN];
void seive(int n) {
	chk[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && p[j] * i <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
bool cmp(que a, que c) {
	if (b[a.l] == b[c.l]) return a.r < c.r;
	else return a.l < c.l;
}
void add(int x) {
	
}
void del(int x) {
}