#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 100010
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
} e[MAXN];
struct E {
	int u, v, w;
} eg[MAXN];
bool cmp(E a, E b) {
	return a.w < b.w;
}
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], _x, _y, z, k, f[MAXN];
int dep[MAXN], son[MAXN], r = 1, fa[MAXN], size[MAXN], top[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs1(int u, int ft, int d) {
	fa[u] = ft;
	dep[u] = d;
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == ft) continue;
		dfs1(to, u, d + 1);
		size[u] += size[to];
		if (size[to] > size[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == son[u] || to == fa[u]) continue;
		dfs2(to, to);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &eg[i].u, &eg[i].v, &eg[i].w);
	}
	std::sort(eg + 1, eg + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		
	}
}