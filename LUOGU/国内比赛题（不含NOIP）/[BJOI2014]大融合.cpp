#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 100010
int si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN];
bool r[MAXN];
int n, m, u, v;
char op[5];
bool ifr(int p) {
	return ls(f[p]) == p || rs(f[p]) == p;
}
void pd(int p) {
	si[p] = si[ls(p)] + si[rs(p)] + val[p] + 1;
}
void flit(int p) {
	int t = ls(p);
	ls(p) = rs(p);
	rs(p) = t;
}
void pushd(int p) {
	if (r[p]) {
		flit(p);
		r[ls(p)] ^= 1;
		r[rs(p)] ^= 1;
		r[p] = 0;
	}
}
void rotate(int p) {
	int x = f[p], y = f[x], k = rs(x) == p, w = c[p][!k];
	if (ifr(x)) c[y][c[y][1] == x] = p;
	c[p][!k] = x;
	c[x][k] = w;
	if (w) f[w] = x;
	f[x] = p;
	f[p] = y;
	pd(x);
}
void splay(int p) {
	int y = p, z = 0;
	st[++z] = y;
	while (ifr(y)) st[++z] = y = f[y];
	while (z) pushd(st[z--]);
	while (ifr(p)) {
		y = f[p];
		z = f[y];
		if (ifr(y)) {
			rotate((ls(y) == p) ^ (ls(z) == y) ? p : y);
		}
		rotate(p);
	}
	pd(p);
}
void access(int p) {
	for (int i = 0; p; p = f[i = p]) {
		splay(p);
		val[p] += si[rs(p)];
		val[p] -= si[rs(p) = i];
		pd(p);
	}
}
void makeroot(int p) {
	access(p);
	splay(p);
	r[p] ^= 1;
}
void split(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x, int y) {
	split(x, y);
	val[f[x] = y] += si[x];
	pd(y);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		si[i] = 1;
	}
	while (m--) {
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'A') {
			link(x, y);
		}
		else {
			split(x, y);
			printf("%d\n", (val[x] + 1) * (val[y] + 1));
		}
	}
}