#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 1000010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, son[MAXN], top[MAXN], fa[MAXN], l[MAXN], s[MAXN], q, a[MAXN];
int dep[MAXN], id[MAXN], c[MAXN], si[MAXN], tim, st[MAXN], tp, lgst, shst = 0x7fffffff, totk;
long long tot;
bool k[MAXN];
std::vector <int> v[MAXN];
bool cmp(int a, int b) {
	return id[a] < id[b];
}
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++tim;
	top[u] = topf;
	// printf("%d\n", u);
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
		printf("%d -> %d\n", st[tp - 1], st[tp]);
		tp--;
	}
	if (lca != st[tp]) {
		v[lca].push_back(st[tp]);
		st[tp] = lca;
	}
	st[++tp] = x;
}
void dfs(int u, int f) {
	if (k[u]) {
		si[u] = 1;
		s[u] = 0;
	}
	else s[u] = 0x3f3f3f3f;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int to = v[u][i];
		if (to == f) continue;
		dfs(to, u);
		si[u] += si[to];
	}
}
void dp(int u, int f) {
	for (int i = 0; i < (int)v[u].size(); i++) {
		int to = v[u][i], w = dep[to] - dep[u];
		if (to == f) continue;
		dp(to, u);
		tot += 1LL * (q - si[to]) * si[to] * w;
		printf("%d %d %d\n", q, si[to], q - si[to]);
		if (si[u] > 0) {
			lgst = std::max(lgst, l[u] + w + l[to]);
			shst = std::min(shst, s[u] + w + s[to]);
		}
		l[u] = std::max(l[u], l[to] + w);
		s[u] = std::min(s[u], s[to] + w);
	}
}
void dfsc(int u, int f) {
	s[u] = l[u] = k[u] = si[u] = 0;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int to = v[u][i];
		if (to == f) continue;
		dfs(to, u);
	}
	v[u].clear();
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	memset(si, 0, sizeof(si));
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			scanf("%d", &a[i]);
			k[a[i]] = 1;
		}
		std::sort(a + 1, a + 1 + q, cmp);
		tot = 0, shst = 0x3f3f3f3f, lgst = 0;
		tp = 1;
		st[tp] = 1;
		for (int i = 1; i <= q; i++) {
			build(a[i]);
		}
		while (tp > 0) v[st[tp - 1]].push_back(st[tp]), tp--;
		dfs(1, 0);
		// puts("OK");`
		dp(1, 0);
		dfsc(1, 0);
		printf("%lld %d %d\n", tot, shst, lgst);
	}
}