#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 100010
int si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN], ifp[MAXN], sz[MAXN], add[MAXN];
bool r[MAXN];
int n, m, u, v, op, zh, _x, _y, e, ans;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
bool ifr(int p) {
	return ls(f[p]) == p || rs(f[p]) == p;
}
void pd(int p) {
	si[p] = si[ls(p)] + si[rs(p)] + val[p];
	sz[p] = sz[ls(p)] + sz[rs(p)] + 1;
}
void addmodify(int p, int c) {
	si[p] += si[p] + c * sz[p];
	val[p] += c;
	add[p] += c;
}
void flit(int p) {
	int t = ls(p);
	ls(p) = rs(p);
	rs(p) = t;
	r[p] ^= 1;
}
void pushd(int p) {
	if (add[p]) {
		if (ls(p)) addmodify(ls(p), add[p]);
		if (rs(p)) addmodify(rs(p), add[p]);
		add[p] = 0;
	}
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
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		link(u, v);
	}
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &u, &v);
			cut(u, v);
		}
		if (op == 2) {
			scanf("%d%d", &u, &v);
			link(u, v);
		}
		if (op == 3) {
			scanf("%d%d%d", &u, &v, &zh);
			makeroot(u);
			if (findr(v) != u) continue;
			split(u, v);
			addmodify(v, zh);
		}
		if (op == 4) {
			scanf("%d%d", &u, &v);
			split(u, v);
			_x = si[v];
			_y = sz[v];
			if (_y & 1) {
				e = (_y + 1) >> 1;
				e *= _y;
			}
			else {
				e = _y >> 1;
				e *= (_y + 1);
			}
			_x *= _y;
			int gg = gcd(_x, e);
			printf("%d/%d\n", _x, e);
		}
	}
}