#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 200010
int si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], fa[MAXN];
bool r[MAXN];
int n, m, u, v;
char op[10];
bool ifr(int p) {
	return ls(fa[p]) == p || rs(fa[p]) == p;
}
void pd(int p) {
	si[p] = si[ls(p)] ^ si[rs(p)] ^ val[p];
}
void flit(int p) {
	int t = ls(p);
	ls(p) = rs(p);
	rs(p) = t;
	r[p] ^= 1;
}
void pushd(int p) {
	if (r[p]) {
		if (ls(p)) flit(ls(p));
		if (rs(p)) flit(rs(p));
		r[p] = 0;
	}
}
void rotate(int p) {
	int x = fa[p], y = fa[x], k = rs(x) == p, w = c[p][!k];
	if (ifr(x)) c[y][c[y][1] == x] = p;
	c[p][!k] = x;
	c[x][k] = w;
	if (w) fa[w] = x;
	fa[x] = p;
	fa[p] = y;
	pd(x);
}
void splay(int p) {
	int y = p, z = 0;
	st[++z] = y;
	while (ifr(y)) st[++z] = y = fa[y];
	while (z) pushd(st[z--]);
	while (ifr(p)) {
		y = fa[p];
		z = fa[y];
		if (ifr(y)) {
			rotate((ls(y) == p) ^ (ls(z) == y) ? p : y);
		}
		rotate(p);
	}
	pd(p);
}
void access(int p) {
	for (int i = 0; p; p = fa[i = p]) {
		splay(p);
		rs(p) = i;
		pd(p);
	}
}
void makeroot(int p) {
	access(p);
	splay(p);
	r[p] ^= 1;
	// flit(p);
}
int findr(int p) {
	access(p);
	splay(p);
	while (ls(p)) {
		pushd(p);
		p = ls(p);
	}
	splay(p);
	return p;
}
void split(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x, int y) {
	makeroot(x);
	fa[x] = y;
}
void cut(int x) {
	// makeroot(x);
	access(x);
	splay(x);
	fa[c[x][0]] = 0;
	c[x][0] = 0;
}
int find(int x, int y) {
	access(x);
	int i;
	for (i = 0; y; i = y, y = fa[y]) {
		splay(y);
		rs(y) = i;
	}
	return i;
}
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%s%d", op, &u);
		if (op[1] == 'i') {
			scanf("%d", &v);
			link(u, v);
		}
		if (op[1] == 'u') {
			cut(u);
		}
		if (op[1] == 'c') {
			scanf("%d", &v);
			printf("%d\n", find(u, v));
		}
	}
}