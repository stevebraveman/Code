#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], a[MAXN], x, y, ecnt, son[MAXN], siz[MAXN], fa[MAXN];
int tim, n, m, dep[MAXN], top[MAXN];
long long p[MAXN], tot;
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
int main() {
	freopen("sagittarius.in", "r", stdin);
	freopen("sagittarius.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(x, i);
		add(i, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &p[i]);
	}
	dfs(1, 1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int lca = a[i];
			for (int k = i; k <= j; k++) {
				lca = LCA(lca, a[k]);
			}
			tot += p[lca];
		}
	}
	printf("%lld\n", tot);
}