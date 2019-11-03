#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define int long long
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ans = 0x7fffffffffffLL, ecnt, a[MAXN], b[MAXN], n, m, x, y, f[MAXN], d[MAXN], z, siz[MAXN], tot;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int fa, int u) {
	siz[u] = a[u];
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs(u, to);
		siz[u] += siz[to];
		d[u] += d[to] + siz[to] * e[i].w;
	}
}
void dfs2(int fa, int u) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		f[to] = f[u] + (tot - siz[to]) * e[i].w - siz[to] * e[i].w;
		dfs2(u, to);
	}
}
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		tot += a[i];
	}
	for (int i = 1; i < n; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(0, 1);
	f[1] = d[1];
	dfs2(0, 1);
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, f[i]);
	}
	printf("%lld", ans);
	return 0;
}
