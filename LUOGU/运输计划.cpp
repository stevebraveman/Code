#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdarg>
#define MAXN 1000010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
template <typename _Tp>
void _read(_Tp &x) {
	x = 0;
	_Tp f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
template <typename _Tp>
void read(size_t n, _Tp* i...) {
	va_list args;
	va_start(args, i);
	_read(*i);
	while (--n) _read(*va_arg(args, _Tp*));
	va_end(args);
}
template <typename _Tp>
void _write(_Tp x) {
	if (x < 0) putchar(45);
	if (x > 9) _write(x / 10);
	putchar(x % 10 + '0');
}
template <typename _Tp>
void write(size_t n, _Tp i...) {
	va_list args;
	va_start(args, i);
	_write(i);
	while (--n) putchar(32), _write(va_arg(args, _Tp));
	va_end(args);
}
void sp() {
	putchar(32);
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, z, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], tot, maxx;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN << 2], c[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = 0;
			c[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void f(int p, int l, int r, int k) {
		b[p] += (r - l + 1) * k;
		lazy[p] += k;
	}
	void pushd(int p, int l, int r) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
			return;
		}
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] += (r - l + 1) * k;
			lazy[p] += k;
			return;
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int l, int r, int p) {
		if (l == r) {
			return b[p] * c[p];
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) return ask(x, l, m, ls(p));
		else return ask(x, m + 1, r, rs(p));
	}
}tr;
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		w[to] = e[i].w;
		dfs1(to, u, deep + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	wt[cnt] = w[u];
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline void qrs(int x, int y, int k) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tr.update(id[top[x]], id[x], 1, n, 1, k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tr.update(id[x] + 1, id[y], 1, n, 1, k);
}
inline int prs(int x) {
	return tr.ask(id[x], 1, n, 1);
}
int main() {
	read(2, &n, &m);
	for (int i = 1; i < n; i++) {
		read(3, &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tr.a[i] = wt[i];
	}
	tr.build(1, 1, n);
	while (m--) {
		read(2, &x, &y);
		qrs(x, y, 1);
	}
	for (int i = 1; i <= n; i++) {
		tot += prs(i);
		maxx = max(maxx, prs(i));
		printf("%d %d\n", tot, maxx);
	}
	write(1, tot - maxx);
	return 0;
}