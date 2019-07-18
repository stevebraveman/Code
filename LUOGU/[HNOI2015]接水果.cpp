#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define INF 1000000000
struct que {
	int l, r, op, k;
}q[MAXN << 2], lq[MAXN << 2], rq[MAXN << 2];
struct Edge {
	int v, nx;
}e[MAXN << 2];
int n, m, rd, a[MAXN], tot, cnt, c[MAXN], head[MAXN], ecnt, ans[MAXN], rdx[MAXN], rdy[MAXN], rdw[MAXN];
int id[MAXN], son[MAXN], fa[MAXN], tim, dep[MAXN], x, y, siz[MAXN], cnt, top[MAXN], r = 1, k, t;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++tim;
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
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	return x;
}
void solve(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		for (int i = st; i <= ed; i++) {
			if (q[i].op > 0) ans[q[i].op] = lval;
		}
		return;
	}
	int lt = 0, rt = 0;
	int mid = (lval + rval) >> 1;
	for (int i = st; i <= ed; i++) {
		if (q[i].op == 0) {
			if (q[i].k <= mid) add(), lq[++lt] = q[i];
			else rq[++rt] = q[i];
		}
		else {
			
		}
	}
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int ask(int x) {
	int y = 0;
	for (; x; x -= x & -x) y += c[x];
	return y;
}
void change(int x, int y) {
	for (; x <= n; x += x & -x) c[x] += y;
}
int main() {
	scanf("%d%d%d", &n, &rd, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= rd; i++) {
		scanf("%d%d%d", &rdx[i], &rdy[i], &rdw[i]);
		q[++t].op = 0;
		q[t].l = rdx[i];
		q[t].r = rdy[i];
		q[t].k = rdw[i];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y, &k);
		q[++t].l = x;
		q[t].op = i;
		q[t].r = y;
		q[t].k = k;
	}
	solve(0, INF, 1, t);
}