// #pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define OK puts("OK")
#define MAXN 400010
#define re register
bool p1;
int a[MAXN * 20], b[MAXN], f[MAXN], ls[MAXN * 20], rs[MAXN * 20], tot = 0, rt[MAXN], lans;
int siz[MAXN], id[MAXN], son[MAXN], fa[MAXN], dep[MAXN], tim, top[MAXN], len;
int head[MAXN], ecnt;
int _t = 0;
template <typename T>
inline void read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
struct Edge {
	int v, nx;
}e[MAXN << 2];
inline void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void insert(int l, int r, int x, int &y, int p) {
	y = ++tot;
	a[y] = a[x] + 1;
	if (l == r) return;
	int m = (l + r) >> 1;
	if (p <= m) rs[y] = rs[x], insert(l, m, ls[x], ls[y], p);
	else ls[y] = ls[x], insert(m + 1, r, rs[x], rs[y], p);
}
void dfs(int ft, int u, int d) {
	dep[u] = d;
	fa[u] = ft;
	siz[u] = 1;
	insert(1, len, rt[ft], rt[u], b[u]);
	// printf("%d %d %d %d %d\n", ft, u, b[u], d, rt[u]);
	for (re int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == ft) continue;
		dfs(u, to, d + 1);
		siz[u] += siz[to];
		if (siz[son[u]] < siz[to]) son[u] = to;
		// printf("%d\n", u);
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (re int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	return x;
}
int ask(int l, int r, int x, int y, int la, int fala, int k) {
	if (l == r) return l;
	int m = (l + r) >> 1;
	int p = a[ls[y]] + a[ls[x]] - a[ls[la]] - a[ls[fala]];
	if (p >= k) return ask(l, m, ls[x], ls[y], ls[la], ls[fala], k);
	else return ask(m + 1, r, rs[x], rs[y], rs[la], rs[fala], k - p);
}
int n, m, l, r, k, x, y;
int main() {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	read(n), read(m);
	for (re int i = 1; i <= n; i++) {
		read(b[i]);
		f[i] = b[i];
	}
	std::sort(f + 1, f + 1 + n);
	len = std::unique(f + 1, f + 1 + n) - f - 1;
	for (re int i = 1; i <= n; i++) {
		b[i] = std::lower_bound(f + 1, f + 1 + len, b[i]) - f;
	}
	for (re int i = 1; i < n; i++) {
		read(x), read(y);
		add(x, y);
		add(y, x);
	}
	dfs(0, 1, 1);
	dfs2(1, 1);
	for (re int i = 1; i <= m; i++) {
		read(l), read(r), read(k);
		l = lans ^ l;
		int lc = LCA(l, r);
		printf("%d\n", lans = f[ask(1, len, rt[l], rt[r], rt[lc], rt[fa[lc]], k)]);
	}
	return 0;
}