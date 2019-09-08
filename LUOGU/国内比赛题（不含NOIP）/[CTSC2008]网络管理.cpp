#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define INF 100000000
struct rec {
    int op, x, y, z;
}q[MAXN << 2], lq[MAXN << 2], rq[MAXN << 2];
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, t, c[MAXN], ans[MAXN], a[MAXN], num, l;
int id[MAXN], son[MAXN], fa[MAXN], tim, dep[MAXN], x, y, siz[MAXN], cnt, top[MAXN], r = 1, k;
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
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	return x;
}
int oper(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans += ask(id[x]) - ask(id[top[x]] - 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans += ask(id[y]) - ask(id[x] - 1);
	return ans;
}
void solve(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		for (int i = st; i <= ed; i++) {
			if (q[i].op > 0 && ans[q[i].op] != -1) ans[q[i].op] = lval;
		}
		return;
	}
	int mid = (lval + rval) >> 1;
	int lt = 0, rt = 0;
	for (int i = st; i <= ed; i++) {
		if (q[i].op == 0) {
			if (q[i].y <= mid) lq[++lt] = q[i];
			else rq[++rt] = q[i], change(id[q[i].x], 1);
		} 
		if (q[i].op == -1) {
			if (q[i].y <= mid) lq[++lt] = q[i];
			else rq[++rt] = q[i], change(id[q[i].x], -1);
		}
		if (q[i].op > 0){
			int cnt = oper(q[i].x, q[i].y);
			if (cnt >= q[i].z) rq[++rt] = q[i];
			else q[i].z -= cnt, lq[++lt] = q[i];
		}
	}
	for (int i = ed; i >= st; i--) {
		if (q[i].op == 0 && q[i].y > mid) change(id[q[i].x], -1);
		if (q[i].op == -1 && q[i].y > mid) change(id[q[i].x], 1);
	}
	for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
	solve(lval, mid, st, st + lt - 1);
	solve(mid + 1, rval, st + lt, ed);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		q[++cnt] = (rec) {0, i, a[i], 0};
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &k, &x, &y);
		if (k != 0) {
			q[++cnt].z = k, q[cnt].x = x, q[cnt].y = y, q[cnt].op = ++num;
			l = dep[x] + dep[y] - 2 * dep[LCA(x, y)] + 1;
			if (l < k) ans[q[cnt].op] = -1;
		}
		else {
			q[++cnt].z = 0, q[cnt].x = x, q[cnt].y = a[x], q[cnt].op = -1;
			q[++cnt].z = 0, q[cnt].x = x, q[cnt].y = y, q[cnt].op = 0;
			a[x] = y;
		}
	}
	solve(1, INF, 1, cnt);
	for (int i = 1; i <= num; i++) {
		if (ans[i] == -1) {
			puts("invalid request!");
		}
		else {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}