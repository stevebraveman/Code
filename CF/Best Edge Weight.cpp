#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200100
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
struct E {
	int u, v, w;
}q[MAXN];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], top[MAXN], son[MAXN], siz[MAXN], id[MAXN], cnt;
int fa[MAXN], w[MAXN], a[MAXN], tmin[MAXN << 2], res;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u, d + 1);
		w[to] = e[i].w;
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	a[cnt] = w[u];
	if (!son[u]) return;
	dfs(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
void pd(int p) {
	tmin[p] = std::min(tmin[ls(p)], tmin[rs(p)]);
}
void build(int l, int r, int p) {
	if (l == r) {
		tmin[p] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls(p));
	build(m + 1, r, rs(p));
	pd(p);
}
int ask(int x, int y, int l, int r, int p) {
	int s = 0x7fffffff;
	if (x <= l && y >= r) {
		return tmin[p];
	}
	int m = (l + r) >> 1;
	if (x <= m) s = std::min(s, ask(x, y, l, m, ls(p)));
	if (y > m) s = std::min(s, ask(x, y, m + 1, r, rs(p)));
	return s;
}
bool cmp(E a, E b) {
	return a.w < b.w;
}
int f[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int query(int x, int y) {
	int ans = 0x7fffffff;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans = std::min(ans, ask(id[x], id[top[x]], 1, n, 1));
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans = std::min(ans, ask(id[x] + 1, id[y], 1, n, 1));
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].w);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	sort(q + 1, q + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		x = e[i].u;
		y = e[i].v;
		if (find(x) == find(y)) {
			f[x] = y;
			add(x, y, e[i].w);
			add(y, x, e[i].w);
		}
	}
	dfs(1, 0, 1);
	dfs2(1, 1);
	build(1, n, 1);
	for (int i = 1; i <= m; i++) {
		res = query(e[i].u, e[i].v);

	}
}