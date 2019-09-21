#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 200100
int si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN];
bool r[MAXN];
int n, m, u, v;
char op[10];
bool ifr(int p) {
	return ls(f[p]) == p || rs(f[p]) == p;
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
		rs(p) = i;
		pd(p);
	}
}
void makeroot(int p) {
	access(p);
	splay(p);
	flit(p);
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
	if (findr(y) != x) f[x] = y;
}
void cut(int x, int y) {
	makeroot(x);
	if (findr(y) == x && f[y] == x && !ls(y)) {
		f[y] = rs(x) = 0;
		pd(x);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'C') {
			link(x, y);
		}
		if (op[0] == 'D') {
			cut(x, y);
		}
		if (op[0] == 'Q') {
			makeroot(x);
			if (findr(y) == x) {
				puts("Yes");
			}
			else {
				puts("No");
			}
		}
	}
}