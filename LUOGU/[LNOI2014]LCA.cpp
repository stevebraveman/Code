#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 50010
#define MOD 201314
struct Edge {
	int v, nx;
}e[MAXN << 1];
struct ques {
	int a1, a2;
}q[MAXN];
struct ques1 {
	int id, ri, pt, fl;
}q1[MAXN << 1];
int head[MAXN], ecnt, n, m, dep[MAXN], son[MAXN], siz[MAXN], pre[MAXN];
int fa[MAXN], cnt, top[MAXN], id[MAXN], a[MAXN], b[MAXN << 2], lazy[MAXN << 2], tim;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	siz[u] = 1;
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	id[u] = ++cnt;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
void pd(int p) {
	b[p] = b[ls(p)] + b[rs(p)];
}
void f(int l, int r, int k, int p) {
	lazy[p] += k;
	b[p] += (r - l + 1) * k;
}
void pushd(int l, int r, int p) {
	if (lazy[p]) {
		int m = (l + r) >> 1;
		f(l, m, lazy[p], ls(p));
		f(m + 1, r, lazy[p], rs(p));
	}
	lazy[p] = 0;
}
void chg(int x, int y, int l, int r, int k, int p) {
	if (x <= l && y >= r) {
		b[p] += (r - l + 1) * k;
		lazy[p] += k;
		return;
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) chg(x, y, l, m, k, ls(p));
	if (y > m) chg(x, y, m + 1, r, k, rs(p));
	pd(p);
}
int ask(int x, int y, int l, int r, int p) {
	int s = 0;
	if (x <= l && y >= r) {
		return b[p];
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) s += ask(x, y, l, m, ls(p));
	if (y > m) s += ask(x, y, m + 1, r, rs(p));
	return s;
}
void cg(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		chg(id[top[x]], id[x], 1, n, 1, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	chg(id[x], id[y], 1, n, 1, 1);
}
int query(int x, int y) {
	int ans = 0;
	// printf("%d %d\n", x, y);
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		// printf("%d %d\n", dep[top[x]], dep[top[y]]);
		ans += ask(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	// printf("%d %d %d %d\n", id[x], id[y], x, y);
	ans += ask(id[x], id[y], 1, n, 1);
	// puts("OK");
	return ans;
}
bool cmp(ques1 a, ques1 b) {
	return a.ri < b.ri;
}
int l, r, x, y, z, npos;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		x++;
		add(i, x);
		add(x, i);
	}
	dfs(1, 0, 1);
	dfs2(1, 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &l, &r, &z);
		// l++;
		r++;
		z++;
		q1[++tim].ri = l;
		q1[tim].id = i;
		q1[tim].pt = z;
		q1[tim].fl = 0;
		q1[++tim].ri = r;
		q1[tim].id = i;
		q1[tim].pt = z;
		q1[tim].fl = 1;
		// scanf("%d%d%d", &q1[i].l, &q[i].r, &q[i].z);
		// q[i].id = i;
	}
	std::sort(q1 + 1, q1 + 1 + tim, cmp);
	for (int i = 1; i <= tim; i++) {
		while (npos < q1[i].ri) {
			cg(1, ++npos);
		}
		x = q1[i].id;
		if (q1[i].fl) q[x].a1 = query(1, q1[i].pt);
		else q[x].a2 = query(1, q1[i].pt);
		// printf("%d %d\n", q[x].a1, q[x].a2);
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", (q[i].a1 - q[i].a2 + MOD) % MOD);
	}
	return 0;
}
/*
5 2
0
0
1
1
1 4 3
1 4 2
----
8
5
 */