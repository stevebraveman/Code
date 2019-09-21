#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 300010
struct Edge {
	int v, nx, w;
}e[MAXN  << 2];
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct E {
	int u, v, w;
}a[MAXN];
int head[MAXN], ecnt, n, m, x, y, dis[MAXN], dep[MAXN], son[MAXN], siz[MAXN], top[MAXN], r = 1, fa[MAXN], fh[MAXN], q;
int dfn[MAXN], low[MAXN], tim, st[MAXN], tp, in[MAXN], p[MAXN], num;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
bool cmp(E a, E b) {
	return a.w < b.w;
}
void tarjan(int u, int f) {
	dfn[u] = low[u] = ++tim;
	st[++tp] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (v == f) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(dfn[v], low[u]);
	}
	if (low[u] == dfn[u]) {
		num++;
		int v;
		do {
			v = st[tp--];
			in[v] = num;
		} while (v != u);
	}
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dis[to] = dis[u] + p[to] + e[i].w;
		dfs1(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[son[u]] < siz[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}
int find(int x) {
	if (fh[x] == x) return x;
	else return fh[x] = find(fh[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
		add(a[i].u, a[i].v, a[i].w);
		add(a[i].v, a[i].u, a[i].w);
	}
	tarjan(1, 0);
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[a[i].u] != in[a[i].v]) {
			add(in[a[i].u], in[a[i].v], a[i].w);
			add(in[a[i].v], in[a[i].u], a[i].w);
		}
		else {
			p[in[a[i].v]] += a[i].w;
		}
	}
	dis[r] = p[r];
	dfs1(r, 0, 1);
	dfs2(r, r);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &x, &y);
		x = in[x];
		y = in[y];
		int lca = LCA(x, y);
		puts(dis[x] + dis[y] - 2 * dis[lca] + p[lca] == 0 ? "NO" : "YES");
	}
}