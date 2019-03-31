#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 100010
#define INF 2000000000
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, p[MAXN], _p[MAXN], dfn[MAXN];
int low[MAXN], num, st[MAXN], ttop, in[MAXN], tim, q, qx, qy;
int dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
std::multiset <int> se[MAXN];
char op[5];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmin[MAXN << 2];
	void pd(int p) {
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int l, int r, int p) {
		if (l == r) {
			b[p] = tmin[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void updated(int x, int l, int r, int p, int k) {
		if (l == r) {
			tmin[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
		pd(p);
	}
	int qmin(int x, int y, int l, int r, int p) {
		int s = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s = min(qmin(x, y, l, m, ls(p)), s);
		if (y > m) s = min(qmin(x, y, m + 1, r, rs(p)), s);
		return s;
	}
}tree;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	st[++ttop] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
			if (low[v] >= dfn[u]) {
				int x;
				num++;
				do {
					x = st[ttop--];
					in[x] = num;
					se[num].insert(_p[x]);
				} while (v != x);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		// printf("%d ", to);
		if (to == f) continue;
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
inline int qrm(int x, int y) {
	int ans = INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = min(tree.qmin(id[top[x]], id[x], 1, n, 1), ans);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = min(tree.qmin(id[x], id[y], 1, n, 1), ans);
	return ans;
}
void upd(int x, int y) {
	tree.updated(id[x], 1, n, 1, y);
}
int  x[MAXN], y[MAXN];
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &_p[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]);
		add(y[i], x[i]);
	}
	memset(p, 0x7f, sizeof(p));
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i, 0);
	}
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (in[y[i]] != in[x[i]]) {
			add(in[x[i]], in[y[i]]);
			add(in[y[i]], in[x[i]]);
		}
	}
	dfs1(r, 0, 1);
	// puts("OK");
	dfs2(r, r);
	for (int i = 1; i <= num; i++) {
		p[i] = *(se[i].begin());
	}
	for (int i = 1; i <= num; i++) {
		tree.a[i] = p[i];
	}
	n = num;
	tree.build(1, n, 1);
	while (q--) {
		scanf("%s", op);
		if (op[0] == 'C') {
			scanf("%d%d", &qx, &qy);
			se[in[qx]].erase(se[in[qx]].find(_p[qx]));
			// se[in[qx]].erase(_p[qx]);
			_p[qx] = qy;
			se[in[qx]].insert(_p[qx]);
			p[in[qx]] = *(se[in[qx]].begin());
			upd(in[qx], p[in[qx]]);
		}
		else {
			scanf("%d%d", &qx, &qy);
			printf("%d\n", qrm(in[qx], in[qy]));
		}
	}
}