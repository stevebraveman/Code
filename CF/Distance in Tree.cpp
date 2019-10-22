#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 50010
struct Edge {
	int v, nx;
} e[MAXN << 1];
int head[MAXN], ecnt, n, k, x, y, son[MAXN], siz[MAXN], dis[MAXN], ans;
int sum[MAXN], r, size, tot;
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge){t, head[f]};
	head[f] = ecnt;
}
void dfs(int f, int u) {
	siz[u] = 1;
	son[u] = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
	if (vis[to] || to == f)
		continue;
		// printf("%d\n", to);
		dfs(u, to);
		siz[u] += siz[to];
		son[u] = std::max(son[u], siz[to]);
 	}
	son[u] = std::max(son[u], size - siz[u]);
	// printf("%d %d\n", u, son[u]);
	if (son[r] > son[u])
	r = u;
}
void dfsdis(int f, int u, int di) {
	dis[++tot] = di;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == f)
		continue;
		dfsdis(u, to, di + 1);
	}
}
int solve(int u, int val) {
	int res = 0;
	tot = 0;
	dfsdis(0, u, val);
	std::sort(dis + 1, dis + 1 + tot);
	int l = 1, _r = tot;
	// puts("----");
	// for (int i = 1; i <= tot; i++) {
	//    printf("%d ", dis[i]);
	// }
	// puts("");
	// puts("----");
	while (l < _r) {
		if (dis[l] + dis[_r] <= k)
		res += (_r - l), l++;
		else
		_r--;
	}
	// puts("-v-");
	// printf("%d %d %d %d\n", tot, l, _r, res);
	// puts("-^-");
	// puts("");
	l = 1, _r = tot;
	while (l < _r) {
		if (dis[l] + dis[_r] < k)
			res -= (_r - l), l++;
		else
			_r--;
	}
	// puts("---");
	// puts("-v-");
	// printf("%d %d %d %d\n", tot, l, _r, res);
	// puts("-^-");
	// printf("%d\n", res);
	return res;
}
void divide(int u) {
	vis[u] = 1;
	ans += solve(u, 0);
	// printf("%d ", ans);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		ans -= solve(to, 1);
		size = siz[to];
		r = 0;
		dfs(0, to);
		// printf("%d %d\n", ans, r);
		divide(r);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	size = son[0] = n;
	r = 0;
	dfs(1, 1);
	// printf("%d\n", r);
	divide(r);
	printf("%d", ans);
}
/*
5 2
1 2
2 3
3 4
2 5

----

5 3
1 2
2 3
3 4
4 5
 */