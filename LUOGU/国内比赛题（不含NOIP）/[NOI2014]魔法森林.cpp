#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 1000000
#define INF 2147483647
#define T 131072
int ans = INF, maxx[MAXN], si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN];
bool r[MAXN];
int n, m, u, v, op;
struct Edge {
	int u, v, a, b;
}e[MAXN << 2];
bool cmp(Edge a, Edge b) {
	return a.a < b.a;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
bool ifr(int p) {
	return ls(f[p]) == p || rs(f[p]) == p;
}
void pd(int p) {
	maxx[p] = p;
	if (e[maxx[p]].b < e[maxx[ls(p)]].b) maxx[p] = maxx[ls(p)];
	if (e[maxx[p]].b < e[maxx[rs(p)]].b) maxx[p] = maxx[rs(p)];
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
	// r[p] ^= 1;
	flit(p);
}
int findr(int p) {
	access(p);
	splay(p);
	while (ls(p)) {
		pushd(p);
		p = ls(p);
	}
	return p;
}
void link(int x) {
	int a = e[x].u, b = e[x].v;
	makeroot(b);
	f[f[b] = x] = a;
}
void cut(int x) {
	access(e[x].u);
	splay(x);
	ls(x) = rs(x) = f[ls(x)] = f[rs(x)] = 0;
	pd(x);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
		e[i].u |= T;
		e[i].v |= T;
	}
	std::sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (e[i].u == e[i].v) continue;
		makeroot(e[i].u);
		if (e[i].u != findr(e[i].v)) link(i);
		else if (e[i].b < e[maxx[e[i].v]].b) cut(maxx[e[i].v]), link(i);
		makeroot(1 | T);
		if ((1 | T) == findr(n | T)) ans = min(ans, e[i].a + e[maxx[n | T]].b);
	}
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}