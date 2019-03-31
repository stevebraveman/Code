#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 2147483648888LL
#define int long long
int swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], son[MAXN], siz[MAXN];
int fa[MAXN], top[MAXN], id[MAXN], cnt, wt[MAXN], w[MAXN], r = 1, f[MAXN], tot;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2];
	void pd(int p) {
		b[p] = max(b[ls(p)], b[rs(p)]);
	}
	void build(int l, int r, int p) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int s = -INF;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s = max(ask(x, y, l, m, ls(p)), s);
		if (y > m) s = max(ask(x, y, m + 1, r, rs(p)), s);
		return s;
	}
}tr;
int find(int t) {
	if (f[t] == t) return t;
	else return f[t] = find(f[t]);
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	siz[u] = 1;
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		w[to] = e[i].w;
		dfs1(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
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
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
int qrmax(int x, int y) {
	int ans = -INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = max(ans, tr.ask(id[top[x]], id[x], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = max(ans, tr.ask(id[x] + 1, id[y], 1, n, 1));
	return ans;
}
struct E {
	int u, v, w;
	bool ifu;
}a[MAXN << 2], b[MAXN << 2];
bool cmp(E a, E b) {
	return a.w < b.w;
}
signed main() {
	w[r] = -INF;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &a[i].u, &a[i].v, &a[i].w);
		b[i] = a[i];
		a[i].ifu = 0;
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	std::sort(a + 1, a + 1 + m, cmp);
	for (int i = 1, tcnt = 0; i <= m; i++) {
		x = find(a[i].u);
		y = find(a[i].v);
		if (x == y) continue;
		f[x] = y;
		tot += a[i].w;
		add(x, y, a[i].w);
		add(y, x, a[i].w);
		tcnt++;
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tr.a[i] = wt[i];
	}
	tr.build(1, n, 1);
	for (int i = 1; i <= m; i++) {
		x = b[i].u;
		y = b[i].v;
		int mina = qrmax(x, y);
		printf("%lld\n", tot - mina + b[i].w);
	}
	return 0;
}