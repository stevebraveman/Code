#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 1000000
#define INF 2147483647
int ans = INF, an[MAXN], si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN], num, now;
bool r[MAXN], b[MAXN];
int n, m, u, v, op, cnt, q;
struct Edge {
	int u, v, a;
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
	an[p] = p;
	if (an[ls(p)] > n && (an[p] <= n || an[p] > an[ls(p)])) an[p] = an[ls(p)];
	if (an[rs(p)] > n && (an[p] <= n || an[p] > an[rs(p)])) an[p] = an[rs(p)];
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
void link(int a, int b) {
	makeroot(b);
	f[b] = a;
}
void cut(int x) {
	access(e[x].u);
	splay(x);
	ls(x) = rs(x) = f[ls(x)] = f[rs(x)] = 0;
	pd(x);
}
void split(int x, int y) {
	makeroot(x);
	access(y);
	splay(y);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].a);
	}
	std::sort(e + 1, e + 1 + m, cmp);
	num = n;
	cnt = 0;
	q = 1;
	for (int i = 1; i <= m; i++) {
		// puts("OK");
		num++;
		if (e[i].u == e[i].v) {
			b[i] = 1;
			continue;
		}
		if (findr(e[i].u) != findr(e[i].v)) {
			link(e[i].u, num);
			link(num, e[i].v);
			cnt++;
		}
		else {
			split(e[i].u, e[i].v);
			now = an[e[i].v];
			b[now - n] = 1;
			splay(now);
			f[ls(now)] = f[rs(now)] = 0;
			link(e[i].u, num);
			link(num, e[i].v);
		}
		while (b[q] && q <= i) q++;
		if (cnt >= n - 1) ans = std::min(ans, e[i].a - e[q].a);
	}
	printf("%d\n", ans);
	return 0;
}