#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 250010
#define int long long
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, id[MAXN], dep[MAXN], son[MAXN], k;
int si[MAXN], st[MAXN], tp, top[MAXN], fa[MAXN], tim, mi[MAXN], a[MAXN];
std::vector <int> v[MAXN];
bool cmp(int a, int b) {
	return id[a] < id[b];
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	si[u] = 1;
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		mi[to] = std::min(mi[u], e[i].w);
		dfs1(to, u, d + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	id[u] = ++tim;
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
void build(int x) {
	if (tp == 1) {
		st[++tp] = x;
		return;
	}
	int lca = LCA(st[tp], x);
	if (lca == st[tp]) return;
	while (tp > 1 && id[st[tp - 1]] >= id[lca]) {
		v[st[tp - 1]].push_back(st[tp]);
		// printf("%d -> %d\n", st[tp - 1], st[tp]);
		tp--;
	}
	if (lca != st[tp]) {
		v[lca].push_back(st[tp]);
		st[tp] = lca;
	}
	st[++tp] = x;
}
int dp(int u) {
	if (v[u].size() == 0) return mi[u];
	int ans = 0;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int to = v[u][i];
		// printf("%d\n", to);
		ans += dp(to);
	}
	v[u].clear();
	return std::min(ans, mi[u]);
}
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i < n; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	memset(mi, 0x7f, sizeof(mi));
	dfs1(1, -1, 1);
	dfs2(1, 1);
	scanf("%lld", &m);
	while (m--) {
		scanf("%lld", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%lld", &a[i]);
		}
		std::sort(a + 1, a + 1 + k, cmp);
		tp = 1;
		st[tp] = 1;
		for (int i = 1; i <= k; i++) {
			build(a[i]);
		}
		// puts("");
		// puts("----");
		while (tp > 0) v[st[tp - 1]].push_back(st[tp]), tp--;
		printf("%lld\n", dp(1));
		// puts("----");
	}
}